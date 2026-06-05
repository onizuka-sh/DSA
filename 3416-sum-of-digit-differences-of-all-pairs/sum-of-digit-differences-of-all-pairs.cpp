class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long n = nums.size();
    if (n < 2) return 0;

    // Assuming all numbers have the same number of digits
    int numDigits = to_string(nums[0]).size();
    vector<vector<long long>> digitCount(numDigits, vector<long long>(10, 0));

    // Count the frequency of each digit at each position
    for (int num : nums) {
        string s = to_string(num);
        for (int i = 0; i < numDigits; ++i) {
            digitCount[i][s[i] - '0']++;
        }
    }

    long long totalDifference = 0;

    // Calculate the total difference based on the digit counts
    for (int i = 0; i < numDigits; ++i) {
        for (int d1 = 0; d1 < 10; ++d1) {
            for (int d2 = 0; d2 < 10; ++d2) {
                if (d1 != d2) {
                    totalDifference += digitCount[i][d1] * digitCount[i][d2];
                }
            }
        }
    }

    // Each difference has been counted twice (d1 with d2 and d2 with d1), so divide by 2
    return totalDifference / 2;
    }
};