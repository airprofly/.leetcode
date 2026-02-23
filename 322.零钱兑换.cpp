/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(const int coinVal:coins){
            for(int i=coinVal;i<=amount;i++){
                if(dp[i-coinVal]==INT_MAX)continue;
                dp[i] = min(dp[i],dp[i-coinVal]+1);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
// @lc code=end

