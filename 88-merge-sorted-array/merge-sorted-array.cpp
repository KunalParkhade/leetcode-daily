class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(m + n, 0); // Temporary vector to store merged result
        int i = 0;
        int j = 0;
        int k = 0;
        
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                result[k++] = nums1[i++];
            } else {
                result[k++] = nums2[j++];
            }
        }

        // Copy the remaining elements from nums1, if any
        while (i < m) {
            result[k++] = nums1[i++];
        }

        // Copy the remaining elements from nums2, if any
        while (j < n) {
            result[k++] = nums2[j++];
        }

        // Copy the merged result back to nums1
        for (int x = 0; x < m + n; x++) {
            nums1[x] = result[x];
        }
    }
};
