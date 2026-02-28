/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        unordered_map<char, vector<int>> text2_map;
        for(int i=0;i<text2.size();i++) text2_map[text2[i]].push_back(i);
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size()));
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+(i+1<text1.size() && j+1<text2.size() ? dp[i+1][j+1] : 0);
                }else{
                    dp[i][j]=max(i+1<text1.size() ? dp[i+1][j] : 0, j+1<text2.size() ? dp[i][j+1] : 0);
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

