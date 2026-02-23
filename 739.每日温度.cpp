/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include<bits/stdc++.h>
using namespace std;

 
// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.empty()) return {};
        stack<int> st;
        vector<int> res(temperatures.size());
        for(int i=temperatures.size()-1;i>=0;--i){
            while(!st.empty()&& temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(st.empty()) {
                res[i]=0;
            }else{
                res[i]=st.top()-i;
            }
            st.push(i);
        } 
        return res;
    }
};
// @lc code=end

