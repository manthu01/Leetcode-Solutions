class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i = n - 1, j = 0;

        while (i >= 0 && j < m) {
            if (nums1[i] > nums2[j]) {
                swap(nums1[i], nums2[j]);
                i--;
                j++;
            } else {
                break;
            }
        }

        sort(nums1.begin(), nums1.begin() + n);
        sort(nums2.begin(), nums2.end());

        for (int k = 0; k < m; k++) {
            nums1[n + k] = nums2[k];
        }
    }
};