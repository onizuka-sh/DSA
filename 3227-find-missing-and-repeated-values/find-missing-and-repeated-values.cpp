class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> s;
        vector<int> ans;
        int a,b,actualSum=0,expectedSum=0;
        int n = grid.size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                actualSum+=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    a=grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expectedSum = (n*n) * (n*n+1)/2;
        b = expectedSum-actualSum+a;
        ans.push_back(b);
        return ans;
    }
};