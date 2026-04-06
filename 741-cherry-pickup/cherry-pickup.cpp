class Solution {
public:
    int n;
    vector<vector<vector<int>>> mem;
    int dfs(vector<vector<int>>& g,int r1,int c1,int r2){
        int c2 = r1+c1-r2;

        if(r1>=n or c1>=n or r2>=n or c2>=n or g[r1][c1]==-1 or g[r2][c2]==-1)
        {
            return INT_MIN;
        }

        if(r1==n-1 and c1==n-1)
        {
            return g[r1][c1];
        }
        if(mem[r1][c1][r2]!=INT_MIN)
        {
            return mem[r1][c1][r2];
        }

        int cherry = g[r1][c1];

        if(r1!=r2 or c1!=c2) cherry+=g[r2][c2];

        int maxCherry = max({dfs(g,r1+1,c1,r2+1),dfs(g,r1,c1+1,r2),dfs(g,r1+1,c1,r2),dfs(g,r1,c1+1,r2+1)});

        cherry+=maxCherry;
        mem[r1][c1][r2] = cherry;
        return cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        mem = vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
        return max(0,dfs(grid,0,0,0));
    }
};