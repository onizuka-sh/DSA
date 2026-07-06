class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i<n; i++) {
            pq.push({profit[i], difficulty[i]});
        }
        int result = 0;
        sort(worker.rbegin(), worker.rend());
        for (int i = 0; i<m; i++) {
            while (!pq.empty() && worker[i] < pq.top().second) pq.pop();
            if (pq.empty()) break;
            result += pq.top().first;
        }
        return result;
    }
};