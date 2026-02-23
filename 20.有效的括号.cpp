/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include<bits/stdc++.h>
using namespace std;
 
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(const char c:s){
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
            }else{
                if(st.empty()) return false;
                char top=st.top();
                st.pop();
                if((c==')' && top!='(') || (c==']' && top!='[') || (c=='}' && top!='{')){
                    return false;
                }
            }
        }
        return st.empty();
    }
};
// @lc code=end

