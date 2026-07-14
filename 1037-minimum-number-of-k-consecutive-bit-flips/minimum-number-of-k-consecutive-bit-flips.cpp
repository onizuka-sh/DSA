class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int res = 0, flip = 0;
        for(int i = 0, n = nums.size(); i < n; ++i){
            if(i - k >= 0 && (nums[i - k] > 1)) flip ^= 1;
            if(nums[i] == flip){
                if(i + k > n) return -1;
                nums[i] = 2;
                flip ^= 1;
                ++res;
            }
        }
        return res;
    }
};