/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {

private: 
    vector<string> ret_;
    string path_;
    vector<string> mapping_={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        _letterCombinations(digits,0);
        return ret_;
    }
private:
    void _letterCombinations(string& digits,int index){
        if(index>=digits.size()){
            ret_.push_back(path_);
            return;
        }
        for(const char& c:mapping_[digits[index]-'2']){
            path_.push_back(c);
            _letterCombinations(digits,index+1);
            path_.pop_back();
        }
        return;
    }
};
// @lc code=end

