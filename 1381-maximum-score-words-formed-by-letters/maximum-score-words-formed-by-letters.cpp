class Solution {
public:
    map<char, int> mp;
    vector<map<char, int>> vmp;
    
    int scores(string word, vector<int>& score) {
        int wordScore = 0;
        for (char ch : word) {
            wordScore += score[ch - 'a'];
        }
        return wordScore;
    }

    bool check(int idx) {
        for (auto& ch : vmp[idx]) {
            if (ch.second > mp[ch.first]) {
                return false;
            }
        }
        return true;
    }
    
    void sol(int idx, vector<string>& words, vector<char>& letters, vector<int>& score, int& mx, int& curr) {
        if (idx >= words.size()) {
            mx = max(mx, curr);
            return;
        }
        //skip the current word
        sol(idx + 1, words, letters, score, mx, curr);
        
        //check if word can be added
        if (check(idx)) {
            for (auto& i : vmp[idx]) {
                mp[i.first] -= i.second;
            }
            int sc = scores(words[idx], score);
            curr += sc;
            sol(idx + 1, words, letters, score, mx, curr);
            curr -= sc;
            for (auto& i : vmp[idx]) {
                mp[i.first] += i.second;
            }
        }
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = letters.size();
        for (int i = 0; i < n; i++) {
            mp[letters[i]]++;
        }

        vmp.resize(words.size()); 
        
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                vmp[i][words[i][j]]++;
            }
        }
        
        int mx = 0;
        int curr = 0;
        sol(0, words, letters, score, mx, curr);
        return mx;
    }
};