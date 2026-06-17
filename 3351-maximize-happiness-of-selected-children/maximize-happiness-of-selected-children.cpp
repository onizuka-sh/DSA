class Solution {
public:
    using ll = long long;
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.rbegin(),h.rend());
        int n = h.size();
        ll ans = 0;
        int cnt = 0;

        for(int i = 0;i < k;i++){
            if(h[i] + cnt >= 0){
                ans += h[i] + cnt;
            }
            cnt--;
        }
        return ans;
    }
};