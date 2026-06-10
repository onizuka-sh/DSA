class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long nextRequiredMinimumSumPossible = 1; int patchedElements = 0, i = 0, size = nums.size();
        while(nextRequiredMinimumSumPossible <= n)
            if(i < size && nextRequiredMinimumSumPossible >= nums[i]) nextRequiredMinimumSumPossible += nums[i] , i++;
            else nextRequiredMinimumSumPossible += nextRequiredMinimumSumPossible, patchedElements++;
        return patchedElements;
    }
};