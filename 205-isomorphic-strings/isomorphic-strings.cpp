class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp1[256] = {};
        int mp2[256] = {};

        for(int i = 0; i < s.size(); i++)
        {
            if(mp1[(unsigned char)s[i]] != mp2[(unsigned char)t[i]])
                return false;

            mp1[(unsigned char)s[i]] = i + 1;
            mp2[(unsigned char)t[i]] = i + 1;
        }

        return true;
    }
};