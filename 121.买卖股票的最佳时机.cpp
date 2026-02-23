/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int prevMin=prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            maxProfit = max(maxProfit, prices[i] - prevMin);
            prevMin = min(prevMin, prices[i]);
        }
        return maxProfit;
    }
};
// @lc code=end

