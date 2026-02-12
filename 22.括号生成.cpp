/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
private:
    vector<string> ret_;
    vector<char> path_;
public:
    vector<string> generateParenthesis(int n) {
        _dfs(n,n);
        return ret_;
    }
private:
    void _dfs(const int left,const int right){
        if(left==0 && right==0){
            ret_.emplace_back(string(path_.begin(),path_.end()));
            return;
        }
        if(left==right){
            path_.emplace_back('(');
            _dfs(left-1,right);
            path_.pop_back();
            return;
        }
        if(right>0)
        {
            path_.emplace_back(')');
            _dfs(left, right - 1);
            path_.pop_back();
        }

        if(left>0)
        {
            path_.emplace_back('(');
            _dfs(left - 1, right);
            path_.pop_back();
        }

        return;
    }
};
// @lc code=end

