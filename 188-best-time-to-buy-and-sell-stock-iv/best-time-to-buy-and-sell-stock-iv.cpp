class Solution {
public:
    int helper(int day, int state, int k,vector<int>& prices,vector<vector<vector<int>>>& memo) {

        if (day == prices.size() || k == 0)
            return 0;

        if (memo[day][state][k] != -1)
            return memo[day][state][k];

        int profit = 0;

        if (state == 0) { 
            int buy = -prices[day] +helper(day + 1, 1, k, prices, memo);
            int skip = helper(day + 1, 0, k, prices, memo);
            profit = max(buy, skip);
        }
        else { 
            int sell = prices[day] + helper(day + 1, 0, k - 1, prices, memo);
            int hold = helper(day + 1, 1, k, prices, memo);
            profit = max(sell, hold);
        }

        return memo[day][state][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo( n,vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return helper(0, 0, k, prices, memo);
    }
};