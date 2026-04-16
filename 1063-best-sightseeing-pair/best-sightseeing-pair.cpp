class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int res=0;
        int max_Till_Now=values[0] +0;   // which is like val[i] +i one part of eqn


        for(int j=1;j<n;j++){
            int a=values[j] -j;
            int b= max_Till_Now;
            res= max(res,a+b);
            max_Till_Now=max(max_Till_Now,values[j]+j);
        }

        return res;




    } 
};