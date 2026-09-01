class Solution {
public:
    string largestOddNumber(string num) {
      int ind=-1,n=num.size();
      for(int i=n-1;i>=0;i--)
      {
        if((num[i]-'0')%2==1)
        {
            ind=i;
            break;
        }
      }
      if(ind==-1) return "";
      else return num.substr(0,ind+1); 
    }
};