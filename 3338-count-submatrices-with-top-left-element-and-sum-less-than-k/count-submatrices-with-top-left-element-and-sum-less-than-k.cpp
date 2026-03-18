class Solution {
public:
    vector<vector<int>> buildPrefixSum(const vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        vector<vector<int>> pre(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i][j] = a[i][j];

                if (i > 0)
                    pre[i][j] += pre[i - 1][j];
                if (j > 0)
                    pre[i][j] += pre[i][j - 1];
                if (i > 0 && j > 0)
                    pre[i][j] -= pre[i - 1][j - 1];
            }
        }

        return pre;
    }
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size(),cnt=0;
        int m=grid[0].size();
        vector<vector<int>> prefSum=buildPrefixSum(grid);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(prefSum[i][j]<=k) cnt++;
            }
        }
        return cnt;
    }
};