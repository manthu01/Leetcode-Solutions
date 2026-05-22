class Solution {
public:
int findPivot(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    int mid = (start + end) / 2;
    while (start < end) {
        if (nums[mid] >= nums[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
        mid = (start + end) / 2;
    }
    return start; // Return the index of the pivot, not the value
}

int binarySearch(vector <int>& nums, int s, int e, int k) {
    int start = s, end = e;
    int mid = (start + end) / 2;
    while (start <= end) {
        if (nums[mid] == k) {
            return mid;
        } else if (nums[mid] > k) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}
    int search(vector<int>& nums, int k) {
     int pivot = findPivot(nums);
    if (k >= nums[pivot] && k <= nums[nums.size()-1]) {
        return binarySearch(nums, pivot, nums.size()-1, k);
    } else {
        return binarySearch(nums, 0, pivot-1, k);
    }
    }
};