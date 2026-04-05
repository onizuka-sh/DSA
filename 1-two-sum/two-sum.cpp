class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++){
            int find=target-nums[i];

            if(m.count(find)){
                return {m[find],i};
            }

            m[nums[i]]=i;
        }

        return {};
    }
};