/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int stairs[3];
        stairs[n%3]=1;
        stairs[(n-1)%3]=1;
        for(int i=n-2;i>=0;i--){
            stairs[i%3]=stairs[(i+1)%3]+stairs[(i+2)%3];
        }
        return stairs[0];
    }
};
// @lc code=end

