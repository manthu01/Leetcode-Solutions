class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n)
        {
            int m=-1;
            for(int i=0;i<n;i++)
            {
                m=max(m,nums[i]);
            }
            return m;
        }
        if(k==1)
        {
            vector<int> freq(51,0);
            for(int i=0;i<n;i++)
            {
                freq[nums[i]]++;
            }
            int x;
            for(int i=50;i>=0;i--)
            {
                if(freq[i]==1)
                {
                    x=i;
                    break;
                }
            }
            return x;
        }
        else
        {
            if(nums[0]==nums[n-1]) return -1;
            int a=1,b=1;
            for(int i=1;i<n-1;i++)
            {
                if(nums[i]==nums[0]) a++;
                if(nums[i]==nums[n-1]) b++;
            }
            if(a>1 && b>1) return -1;
            else if(a==1 && b==1) return max(nums[0],nums[n-1]);
            else if(a==1) return nums[0];
            else return nums[n-1];
        }
    }
};