class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency
        for (char c : s) {
            freq[c]++;
        }

        int n = s.size();

        // Step 2: Create buckets
        vector<vector<char>> bucket(n + 1);

        // Step 3: Fill buckets
        for (const auto &p : freq) {
            bucket[p.second].push_back(p.first);
        }

        // Step 4: Build answer
        string ans;
        ans.reserve(s.size());

        for (int i = n; i >= 1; --i) {
            for (char c : bucket[i]) {
                ans += string(i, c);
            }
        }

        return ans;
    }
};