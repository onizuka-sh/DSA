class Solution {
public:
    int longestSubarray(vector<int>& vec, int limit) {
        int n=vec.size();
        int ans=0;
        deque<pair<int,int>> mini, maxi;
        for(int i=0, j=0;j<n;j++){
            while(!mini.empty() && mini.back().first>=vec[j]) mini.pop_back();
            while(!maxi.empty() && maxi.back().first<=vec[j]) maxi.pop_back();
            mini.push_back({vec[j], j});
            maxi.push_back({vec[j], j});
            if(maxi.front().first-mini.front().first<=limit) ans=max(ans, j-i+1);
            while(!maxi.empty() && !mini.empty() && maxi.front().first-mini.front().first>limit) {
                if(maxi.front().second<=i) maxi.pop_front();
                if(mini.front().second<=i) mini.pop_front();
                i++;
            }
        }
        return ans;
    }
};