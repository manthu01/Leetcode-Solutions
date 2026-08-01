class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int l = 0;
        string ans = "";

        for (int r = 0; r <= n; r++) {
            if (r == n || s[r] == ' ') {
                if (r > l) {   // Ignore multiple spaces
                    if (ans.empty())
                        ans = s.substr(l, r - l);
                    else
                        ans = s.substr(l, r - l) + " " + ans;
                }
                l = r + 1;
            }
        }

        return ans;
    }
};