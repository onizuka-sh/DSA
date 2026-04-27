class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Sort the seats array
        std::sort(seats.begin(), seats.end());
        
        // Sort the students array
        std::sort(students.begin(), students.end());
        
        // Initialize the count of moves to 0
        int count = 0;
        
        // Iterate through the sorted arrays
        for (int i = 0; i < seats.size(); i++) {
            // Calculate the absolute difference between the seat and student positions
            count += std::abs(seats[i] - students[i]);
        }
        
        // Return the total count of moves
        return count;
    }
};