class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        bool flag=1;
        int maxIndex=nums[0];
        while(i<n)
        {
            if(i>maxIndex)
            {
                flag=0;
                break;
            }
            int currMax=i+nums[i];
            maxIndex=max(maxIndex,currMax);
            if(maxIndex>=n) break;
            i++;
        }
        if(flag) return 1;
        else return 0;
    }
};