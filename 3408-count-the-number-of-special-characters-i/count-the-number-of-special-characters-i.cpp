class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> big(26,0);
        vector<int> small(26,0);
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if((int)word[i]<97) big[word[i]-'A']++;
            else small[word[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(big[i]>0 && small[i]>0) count++;
        }
        return count;
    }
};