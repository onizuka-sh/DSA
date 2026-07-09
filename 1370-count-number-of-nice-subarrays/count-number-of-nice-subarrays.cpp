class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int i = 0, a = -1, b = -1, n = nums.size(), cnt = 0, ans = 0;

         // First, find the first window that contains exactly k odd numbers
        while (cnt < k && i < n) {
            if (nums[i] % 2 == 1) { // Check if the number is odd
                cnt++;              // Increment the odd count
                if (b == -1)        // Set the initial right boundary
                    b = i;
            }
            i++;
        }

        // If there are not enough odd numbers to make a window of k odd numbers
        if (cnt < k)
            return 0;
        
        // Calculate the number of subarrays for the initial window
        ans = b - a;

        // Continue iterating through the rest of the array
        while (i < n) {
            if (nums[i] % 2 == 1) { // Check if the current number is odd
                a = b;              // Move the left boundary to the previous right boundary
                b++;
                while (b < n) {
                    if (nums[b] % 2 == 1) // Find the next odd number
                        break;
                    b++;
                }
            }
            ans += b - a; // Add the number of valid subarrays ending at the current position
            i++;
        }
        return ans; // Return the total number of valid subarrays
    }
};