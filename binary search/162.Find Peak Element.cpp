class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // method : binary search
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < nums[m + 1]) l = m + 1;
            else r = m; 
        }
        return nums[r] > nums[l] ? r : l;
        // time complexity: O(logn)
        // space complexity: O(1)
    }
};