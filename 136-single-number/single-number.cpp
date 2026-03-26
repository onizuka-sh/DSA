class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(auto x:nums){
            int flag=0;
            for(auto y:nums){
                if(x==y)flag++;
            }
            if (flag==1)return x;
        }
        return -1;
    }
};