/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
private:
    vector<int> dp;
    vector<int> square;
public:
    int numSquares(int n) {
        dp.resize(n+1,INT_MAX);
        _initSquare(n);

        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<square.size()&&square[j]<=i;j++){
                dp[i]=min(dp[i],dp[i-square[j]]+1);
            }
        }
        return dp[n];
    }
private:
    void _initSquare(int n){
        for (int i = 1; i*i <= n; i++)
        {
            square.push_back(i*i);
        }
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Solution s;
    
    s.numSquares(12);
    
    return 0;
}

