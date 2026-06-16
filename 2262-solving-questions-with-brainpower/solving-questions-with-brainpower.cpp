class Solution {
        long long helper(vector<vector<int>>& q, int i,vector<long long>& memo) {
            if (i >= (int)q.size()) return 0;
            if (memo[i] != -1) return memo[i];

            long long solve = q[i][0] + helper(q, i + q[i][1] + 1, memo);

            long long skip  = helper(q, i + 1, memo);

            return memo[i] = max(solve, skip);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> memo(n + 1, -1);
        return helper(questions, 0, memo);
    }
};