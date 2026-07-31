class Solution {
    set<vector<int>> ans;
public:
    void helper(vector<int>& nums,int index,vector<int> temp)
    {
        if(index>=nums.size())
        {
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[index]);
        ans.insert(temp);
        helper(nums,index+1,temp);
        temp.pop_back();
        ans.insert(temp);
        helper(nums,index+1,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(),nums.end());
        helper(nums,0,result);
        vector<vector<int>> x(ans.begin(),ans.end());
        return x;
    }
};