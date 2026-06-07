class Solution {
public:
    bool isPossible(vector<int>& position, int distance, int m) {
        int balls = 1;
        int lastPosition = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPosition >= distance) {
                balls++;
                lastPosition = position[i];
            }

            if (balls >= m) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 0;
        int high = position.back() - position.front();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(position, mid, m)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};