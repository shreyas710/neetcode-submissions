class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int total = n + m;
        int mid = total / 2;
        int prev = 0, curr = 0;

        int i = 0, j = 0;

        for (int k = 0; k <= mid; k++) {
            prev = curr;
            if (j >= m || (i < n && nums1[i] <= nums2[j])) 
                curr = nums1[i++];
            else 
                curr = nums2[j++];
        }

        return total % 2 ? curr : (prev + curr) / 2.0;
    }
};
