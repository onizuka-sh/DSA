class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int p1=0;p1<nums.size();p1++){
            for(int p2=p1+1;p2<nums.size();p2++)if(nums[p1]+nums[p2]==target) return {p1,p2};         
        }
        return {};
    }
};