class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> n1;
        map<int,int> n2;

        int n = nums1.size();
        int m = nums2.size();
        
        int limit = min(n, m);

        int i = 0;

        for(i = 0; i < limit; i++)
        {
            n1[nums1[i]]++;
            n2[nums2[i]]++;

            if(nums1[i] < nums2[i])
            {
                if(n1[nums1[i]] >= 1 && n2[nums1[i]] >= 1)
                    return nums1[i];
            }
            else
            {
                if(n2[nums2[i]] >= 1 && n1[nums2[i]] >= 1)
                    return nums2[i];
            }
        }

        while(i < n)
        {
            n1[nums1[i]]++;

            if(n2[nums1[i]] >= 1)
                return nums1[i];

            i++;
        }

        while(limit < m)
        {
            n2[nums2[limit]]++;

            if(n1[nums2[limit]] >= 1)
                return nums2[limit];

            limit++;
        }

        return -1;
    }
};