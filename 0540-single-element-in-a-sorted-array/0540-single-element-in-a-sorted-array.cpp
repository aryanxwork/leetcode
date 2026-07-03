class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid % 2 == 1) mid--;  // ensure mid is even
            
            if (nums[mid] == nums[mid + 1]) {
                lo = mid + 2;  // single element is on the right
            } else {
                hi = mid;      // single element is at mid or on the left
            }
        }
        return nums[lo];
    }
};