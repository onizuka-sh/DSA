class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int countSort[10001] = {0};
        
        for(int i = 0; i < nums.size(); i++){
            countSort[nums[i]]++;
        }  

        int dp[10001] = {0};
        dp[1] = countSort[1];

        for(int i = 2; i < 10001; i++){
            dp[i] = max(dp[i-1], dp[i-2] + i * countSort[i]);
        }      

        return dp[10000];
    }
};