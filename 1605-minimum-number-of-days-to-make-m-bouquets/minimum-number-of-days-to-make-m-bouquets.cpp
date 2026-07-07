class Solution {
public:
    #define ll long long

    // Helper function:
    // Checks if it is possible to make at least m bouquets
    // by day = mid
    bool canMake(int mid, vector<int>& nums, int m, int k) {

        int count = 0;  // number of bouquets formed
        int i = 0;

        while(i < nums.size()) {

            // If flower has bloomed by day mid
            if(nums[i] <= mid) {

                int required = k;

                // Try to take k consecutive bloomed flowers
                while(i < nums.size() && nums[i] <= mid && required > 0) {
                    required--;
                    i++;
                }

                // If we successfully took k flowers → 1 bouquet formed
                if(required == 0)
                    count++;
            }
            else {
                // Flower not bloomed → move ahead
                i++;
            }
        }

        // Check if we formed enough bouquets
        return count >= m;
    }

    int minDays(vector<int>& nums, int m, int k) {

        // If total flowers required exceed available flowers
        if((ll)m * k > nums.size())
            return -1;

        // Search space for binary search
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());

        int ans = -1;

        // Binary Search on minimum day
        while(lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if(canMake(mid, nums, m, k)) {
                ans = mid;      // possible answer
                hi = mid - 1;   // try to minimize days
            }
            else {
                lo = mid + 1;   // need more days
            }
        }

        return ans;
    }
};