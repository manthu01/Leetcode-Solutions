class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int i=startIndex%n,a=0,b=0;
        while(words[i]!=target)
        {
            i++;
            i%=n;
            a++;
            if(a>1000) return -1;
        }
        i=startIndex%n;
        while(words[i]!=target)
        {
            i=(i-1+n)%n;
            i%=n;
            b++;
        }
        if(a>b) return b;
        else return a;
    }
};