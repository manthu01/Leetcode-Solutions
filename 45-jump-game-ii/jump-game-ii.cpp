class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            // Furthest we can reach from current range
            farthest = max(farthest, i + nums[i]);

            // Current range is exhausted
            if(i == currentEnd)
            {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};