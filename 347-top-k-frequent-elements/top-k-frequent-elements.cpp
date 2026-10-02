class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {// TC : O(N) Average & SC : O(N)
        //N = nums.size()
        //U = number of unique elements, U <= N
        //K = k, K <= U <= N
        
        unordered_map<int,int>mp;// SC : O(U), since U ≤ N so, SC : O(N)
        vector<int>ans;// SC : (K), since K<=U<=N so, SC : O(N)
 
        for(int i=0;i<nums.size();i++){// TC : O(N)

            mp[nums[i]]++;// TC : average O(1)

        }

        //bucket[i] contains elements appearing i times
        vector<vector<int>>bucket(nums.size()+1);// TC : O(N) and SC : O(N)

        for(auto it : mp){// TC : O(U) ---> TC : O(N)

            int ele = it.first;
            int freq = it.second;

            bucket[freq].push_back(ele);
        }


        // Outer loop runs N times.
        // Across all buckets, the inner loop processes each unique element once.
        // Therefore total TC = O(N + U) = O(N).

        for(int f = nums.size();f>=1;f--){// TC : O(N)

            for(int element : bucket[f]){// TC : O(U)

                ans.push_back(element);// TC : O(K)

                if(ans.size() == k){

                    return ans;
                }
            }
        }


        return ans;
    }
};