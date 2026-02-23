/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> charLastPosMap;
        for(int i=0;i<s.size();i++){
            charLastPosMap[s[i]]=i;
        }
        vector<int> ret;
        int curPos=0;
        while(curPos<s.size()){
            int maxPos=charLastPosMap[s[curPos]];
            for(int i=curPos+1;i<=maxPos;i++){
                maxPos=max(maxPos,charLastPosMap[s[i]]);
            }
            ret.push_back(maxPos-curPos+1);
            curPos=maxPos+1;
        }
        return ret;
    }
};
// @lc code=end

