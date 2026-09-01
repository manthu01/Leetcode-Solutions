class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        string ans = "";
        vector<int> lengths;
        int n = strs.size();

        for(int i = 0; i < n; i++)
        {
            lengths.push_back(strs[i].size());
        }

        int j = 0;

        while(true)
        {
            bool flag = 1;

            for(int i = 0; i < n - 1; i++)
            {
                if(j == lengths[i] || 
                   j == lengths[i + 1] || 
                   strs[i][j] != strs[i + 1][j])
                {
                    flag = 0;
                    break;
                }
            }

            if(flag == 0)
            {
                break;
            }

            ans += strs[0][j];
            j++;
        }

        return ans;
    }
};