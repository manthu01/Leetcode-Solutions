class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
      int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> res;
        int x=nums[0],i=0;
        while(x!=nums[n-1])
            {
                if(nums[i]==x) 
                {
                    i++;
                    x++;
                }
                else
                {
                    res.push_back(x);
                    x++;
                }
            }
        return res;
    }
};