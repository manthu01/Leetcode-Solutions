class Solution {
public:
    int buildPrefixSum(const vector<vector<char>>& a) {
    int n = a.size();
    int m = a[0].size(), cnt = 0;

    vector<vector<int>> sum(n, vector<int>(m, 0));
    vector<vector<int>> countX(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // build sum matrix
            if (a[i][j] == 'X') sum[i][j] = 1;
            else if (a[i][j] == 'Y') sum[i][j] = -1;

            // build countX matrix
            if (a[i][j] == 'X') countX[i][j] = 1;

            // prefix build
            if (i > 0) {
                sum[i][j] += sum[i - 1][j];
                countX[i][j] += countX[i - 1][j];
            }
            if (j > 0) {
                sum[i][j] += sum[i][j - 1];
                countX[i][j] += countX[i][j - 1];
            }
            if (i > 0 && j > 0) {
                sum[i][j] -= sum[i - 1][j - 1];
                countX[i][j] -= countX[i - 1][j - 1];
            }

            // check condition
            if (sum[i][j] == 0 && countX[i][j] > 0)
                cnt++;
        }
    }

    return cnt;
}
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        return buildPrefixSum(grid);
    }
};




