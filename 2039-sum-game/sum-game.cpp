class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int lc = 0, rc = 0;
        int lsum = 0, rsum = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                lc++;
            else
                lsum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rc++;
            else
                rsum += num[i] - '0';
        }

        if ((lc + rc) % 2)
            return true;

        int diff = lsum - rsum;
        int target = (rc - lc) / 2 * 9;

        return diff != target;
    }
};