class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());

        int ans = 0;
        int m = heaters.size();

        for (int house : houses) {
            int low = 0, high = m - 1;

            // Find first heater >= house
            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (heaters[mid] < house)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            int leftDist = INT_MAX;
            int rightDist = INT_MAX;

            if (low < m)
                rightDist = heaters[low] - house;

            if (low > 0)
                leftDist = house - heaters[low - 1];

            ans = max(ans, min(leftDist, rightDist));
        }

        return ans;
    }
};