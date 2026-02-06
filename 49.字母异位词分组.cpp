/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include<bits/stdc++.h>
using namespace std;

int hash(const string& str){
    int h=0;
    for(char c:str){
        h+=c;
    }
    return h;
}

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<multiset<char>,vector<int>> char_map;
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            multiset<char> temp_set;
            for(char c:str){
                temp_set.insert(c);
            }
            char_map[temp_set].push_back(i);
        }

        vector<vector<string>>res;
        for(auto pair:char_map){
            vector<string> group;
            for(int index:pair.second){
                group.push_back(strs[index]);
            }
            res.push_back(group);
        }
        return res;
    }
};
// @lc code=end

