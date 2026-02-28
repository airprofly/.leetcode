/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].begin(), grid[0].end());
        // dp.insert(dp.begin(), 0);
        partial_sum(dp.begin(), dp.end(), dp.begin());
        for(int i=1;i<grid.size();i++){
            dp[0]+=grid[i][0];
            for(int j=1;j<grid[0].size();j++){
                dp[j]=min(dp[j-1], dp[j])+grid[i][j];
            }
        }
        return dp.back();
    }
};
// @lc code=end

