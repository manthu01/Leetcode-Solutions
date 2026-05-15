class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size(),start = 0, end = n - 1;
    int mid = (start + end) / 2;
    while (start <end)
    {
        if (arr[mid] <arr[end])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return arr[start];
    }
};