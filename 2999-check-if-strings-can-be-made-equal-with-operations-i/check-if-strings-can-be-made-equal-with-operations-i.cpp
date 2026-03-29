class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string x1 = {s1[2], s1[1], s1[0], s1[3]};
        string x2 = {s1[0], s1[3], s1[2], s1[1]};
        string x3 = {s1[2], s1[3], s1[0], s1[1]};
        
        return (s1 == s2 || s2 == x1 || s2 == x2 || s2 == x3);
    }
};