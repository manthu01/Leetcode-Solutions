class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        priority_queue<int,vector<int>,greater<int>> masses(asteroids.begin(),asteroids.end());
        int n=asteroids.size();
        long long m=mass;
        for(int i=0;i<n;i++)
        {
            if(masses.top()>m) return false;
            else
            {
                m+=masses.top();
                masses.pop();
            }
        }
        return true;
    }
};