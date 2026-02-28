/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        // stack<int> st;
        // vector<int> dp(s.size(),0);
        // int ret=0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='('){
        //         st.push(i);
        //         continue;
        //     }
        //     if(st.empty()) continue;
        //     int left=st.top();
        //     st.pop();
        //     if(left) dp[i]=dp[left-1]+i-left+1;
        //     else dp[i]=i-left+1;
        //     ret=max(ret,dp[i]);
        // }
        // return ret;
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if (left == right)
            {
                maxlength = max(maxlength, 2 * right);
            }
            else if (right > left)
            {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = (int)s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if (left == right)
            {
                maxlength = max(maxlength, 2 * left);
            }
            else if (left > right)
            {
                left = right = 0;
            }
        }
        return maxlength;

    }
};
// @lc code=end

