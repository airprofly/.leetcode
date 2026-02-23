/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(const char c:s){
            if(c!=']'){
                st.push(c);
                continue;
            }
            string str;
            while(!st.empty()&& st.top()!='['){
                str=st.top()+str;
                st.pop();
            }
            st.pop(); //弹出'['
            string numStr;
            while(!st.empty() && isdigit(st.top())){
                numStr=st.top()+numStr;
                st.pop();
            }
            int num=stoi(numStr);
            for(int i=0;i<num;++i){
                for(const char c:str){
                    st.push(c);
                }
            }
        }
        string res;
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};
// @lc code=end

