class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size(),m=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int curr=0;
            while(nums[i]!=0)
            {
                curr+=(nums[i]%10);
                nums[i]/=10;
            }
            m=min(curr,m);
        }
        return m;
    }
};