
class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0, b = 0, c = 0;
        int count = 0;
        int n = s.size();
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (s[r] == 'a') a++;
            if (s[r] == 'b') b++;
            if (s[r] == 'c') c++;

            while (a > 0 && b > 0 && c > 0) {
                count += n - r;

                if (s[l] == 'a') a--;
                if (s[l] == 'b') b--;
                if (s[l] == 'c') c--;
                l++;
            }
        }

        return count;
    }
};
