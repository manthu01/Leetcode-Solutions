class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxi;
        vector<int> mini;
        int n=nums.size();
        int a=INT_MIN,b=INT_MAX;
        for(int i=0;i<n;i++)
        {
            a=max(a,nums[i]);
            b=min(b,nums[n-i-1]);
            maxi.push_back(a);
            mini.push_back(b);
        }
        for(int i=0;i<n;i++)
        {
            if(maxi[i]-mini[n-i-1]<=k) return i;
        }
        return -1;
    }
};