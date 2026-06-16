class Solution {
    int helper(vector<string>& strs, int i, int j, int k,vector<vector<vector<int>>>& memo) {
        if (i == (int)strs.size()) return 0;
        if (memo[i][j][k] != -1) return memo[i][j][k];

        
        int zeros = count(strs[i].begin(), strs[i].end(), '0');
        int ones  = strs[i].size() - zeros;
        
        int skip = helper(strs, i+1, j, k, memo);

        int take = 0;
        if (j >= zeros && k >= ones)
            take = 1 + helper(strs, i+1, j-zeros, k-ones, memo);

        return memo[i][j][k] = max(skip, take);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> memo(sz, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return helper(strs, 0, m, n, memo);
    }
};