class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros=0;
        int n=nums.size();
        int l=0;
        int curr=0;
        int m=INT_MIN;
        for(int r=0;r<n;r++)
        {
            if(nums[r]==0)
            {
                zeros++;
            }
            curr++;
            if(zeros>k)
            {
                while(zeros>k)
                {
                    curr--;
                    if(nums[l]==0) zeros--;
                    l++;
                }
            }
            m=max(m,curr);
        }
        return m;
    }
};