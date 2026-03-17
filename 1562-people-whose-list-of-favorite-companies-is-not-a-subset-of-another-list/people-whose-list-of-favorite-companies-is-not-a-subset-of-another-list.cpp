class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();

        // Convert to sets once
        vector<unordered_set<string>> sets(n);
        for (int i = 0; i < n; i++) {
            sets[i] = unordered_set<string>(
                favoriteCompanies[i].begin(),
                favoriteCompanies[i].end()
            );
        }

        // Store indices
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        // Sort indices by size (descending)
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return sets[a].size() > sets[b].size();
        });

        vector<int> res;

        for (int i = 0; i < n; i++) {
            bool isSubsetOfAny = false;

            for (int j = 0; j < i; j++) {
                // only check larger sets
                if (sets[idx[j]].size() < sets[idx[i]].size()) continue;

                bool isSubset = true;
                for (auto &s : sets[idx[i]]) {
                    if (!sets[idx[j]].count(s)) {
                        isSubset = false;
                        break;
                    }
                }

                if (isSubset) {
                    isSubsetOfAny = true;
                    break;
                }
            }

            if (!isSubsetOfAny) {
                res.push_back(idx[i]);
            }
        }

        // return in sorted order
        sort(res.begin(), res.end());
        return res;
    }
};