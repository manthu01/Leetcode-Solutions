class Solution {
public:
    string trimTrailingVowels(string s) {
        int i = s.size() - 1;
        set<char> se = {'a','e','i','o','u'};
        
        while (i >= 0 && se.count(s[i])) {
            i--;
        }
        
        return s.substr(0, i + 1);
    }
};