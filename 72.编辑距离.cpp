/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

#include<bits/stdc++.h>
using namespace std;

 
// @lc code=start
class Solution {
private:
    int _add(int a,int b){
        if(a == INT_MAX) return a;
        return a + b;
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, INT_MAX));
        for(int i=0;i<=word1.size();i++){
            dp[i][0] = i;
        }
        for(int j=0;j<=word2.size();j++){
            dp[0][j] = j;
        }
        for(int i=0;i<word1.size();i++){
            for(int j=0;j<word2.size();j++){
                dp[i+1][j+1]=min({
                    _add(dp[i][j+1],1), // delete
                    _add(dp[i+1][j],1), // insert
                    _add(dp[i][j],1),// replace
                });
                if(word1[i] == word2[j]){
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
                }
            }   
        }
        // for(int j=1;j<=word2.size();j++){
        //     dp[word1.size()][j]=min(dp[word1.size()][j], _add(dp[word1.size()][j-1], 1));
        // }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end

