class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n);
        vector<bool> seenA(n+1, false), seenB(n+1, false);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            seenA[A[i]] = true;
            seenB[B[i]] = true;

            if (seenA[A[i]] && seenB[A[i]]) cnt++;
            if (A[i] != B[i] && seenA[B[i]] && seenB[B[i]]) cnt++;

            result[i] = cnt;
        }
        return result;
    }
};
