/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // int step = m + n - 2;
        // int choose = min(m - 1, n - 1);
        // long long res = 1;
        // return _C(step, choose);
        vector<int> dp(n+1,1);
        dp[0]=0;
        for(int i=1;i<m;i++){
            for(int j=1;j<n+1;j++){
                dp[j]+=dp[j-1];
            }
        }
        return dp[n];
    }

private:
    /**
     * @brief Computes the binomial coefficient C(n, m), which is the number of ways to choose m elements from a set of n elements.
     *
     * This function calculates the value of "n choose m" (also known as the binomial coefficient) using an efficient iterative approach to avoid overflow and redundant calculations.
     *
     * @param n The total number of elements.
     * @param m The number of elements to choose.
     * @return The binomial coefficient C(n, m) as a long long integer. Returns 0 if m > n.
     */
    long long _C(int n, int m)
    {
        if (m > n)
            return 0;
        if (m == 0 || m == n)
            return 1;
        if (m > n - m)
            m = n - m;
        long long res = 1;
        for (int i = 0; i < m; i++)
        {
            res = res * (n - i) / (i + 1);
        }
        return res;
    }
};
// @lc code=end
