/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
private:
    unordered_map<int,unordered_set<int>> char_indices_map_;
    
public:
    vector<vector<string>> partition(string s) {
        for(int i=0;i<s.size();i++){
            char_indices_map_[s[i]].insert(i);
        }
        return _dfs(s,0);
    }
private:
    bool _is_palindrome(const string& s, const int left,const int right){
        if(left<0 || right>=s.size()) return false;
        if(left>=right) return true;
        if(s[left]!=s[right]) return false;
        return _is_palindrome(s, left+1,right-1);
    }

    vector<vector<string>> _dfs(const string& s,const int start){
        if(start<0 || start>=s.size()){
            return {{}};
        }
        vector<vector<string>> ret;
        for(const int index:char_indices_map_[s[start]]){
            if(index<start) continue;
            if(_is_palindrome(s,start,index)){
                string palin_substr=s.substr(start,index-start+1);
                vector<vector<string>> sub_ret=_dfs(s,index+1);
                for(auto& vec:sub_ret){
                    vec.insert(vec.begin(),palin_substr);
                    ret.emplace_back(vec);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

