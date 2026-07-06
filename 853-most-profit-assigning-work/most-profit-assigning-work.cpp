class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        vector<pair<int, int>> vec (n);
        for (int i = 0; i<n; i++) {
            vec[i] = {difficulty[i], profit[i]};
        }
        sort(vec.begin(), vec.end());
        for (int i = 1; i<n; i++) {
            vec[i].second = max(vec[i].second, vec[i-1].second);
        }
        int totalProfit = 0;
        for (int i = 0; i<m; i++) {
            int l = 0, r = vec.size()-1;
            int currProfit = 0;
            while (l<=r) {
                int mid = l+(r-l)/2;
                if (worker[i] >= vec[mid].first) {
                    l = mid+1;
                    currProfit = vec[mid].second;
                }
                else r = mid-1;
            }
            totalProfit += currProfit;
        }
        return totalProfit;
    }
};