class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freqCount;  // character --> frequency  
        
        // Step-1 Count the Frequency of each distinct character of a String.
        for(char ch : s)
            freqCount[ch]++;

        priority_queue<pair<int,char>> maxHeap;     // frequency --> character

        // Step-2 Push the Pair of {Frequency, Character} in the Max Heap.
        for(auto p : freqCount)  
            maxHeap.push({p.second, p.first});
        
        string res = "";
        char lastCh;    // Last Inserted Character in Resultant String.

        // Step-3 Pop the two Pairs of {Frequency, Character} with Highest Frequency from the Max Heap.
        //        and add them in the res and Push again {Frequency-1, Character} again if Frequency != 1.
        while(!maxHeap.empty()){
            
            auto pair1 = maxHeap.top();     // Pair with Highest Frequency
            maxHeap.pop();
            char ch1 = pair1.second;    // Character with Highest Frequency

            // If the Last inserted Character and Current Character becomes equal and maxHeap is Empty return Empty String.
            if((ch1 == lastCh) && maxHeap.empty()) return "";  
            res += ch1;     // Adding Current Character in res.
            lastCh = ch1;   // Updating Last inserted Character.

            if(!maxHeap.empty()){
                auto pair2 = maxHeap.top(); // Pair with Second Highest Frequency
                maxHeap.pop();
                char ch2 = pair2.second;    // Character with Second Highest Frequency
                res += ch2;     // Adding Current Character in res.
                lastCh = ch2;   // Updating Last inserted Character.

                if(pair2.first != 1)    // Again Adding Back Charcter with 1 Less frequency
                    maxHeap.push({pair2.first-1,ch2});
            }
            
            if(pair1.first != 1)    // Again Adding Back Charcter with 1 Less frequency
                maxHeap.push({pair1.first-1,ch1});
        }
        return res;
    }
};