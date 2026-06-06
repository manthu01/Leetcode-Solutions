class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size(),left=0,right=0;
        vector<int> difference(n);
        for(int i=0;i<n;i++)
        {
            right+=nums[i];
        }
        right-=nums[0];
        difference[0]=abs(left-right);
        for(int i=1;i<n;i++)
        {
            left+=nums[i-1];
            right-=nums[i];
            difference[i]=abs(left-right);
        }
        return difference;
        
    }
};