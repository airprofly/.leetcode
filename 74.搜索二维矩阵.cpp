/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        vector<vector<int>>::iterator it= lower_bound(matrix.begin(),matrix.end(),target,[](const vector<int>& a,const int tar){
            return a.back()<tar;
        });
        if(it==matrix.end()) return false;
        return binary_search(it->begin(),it->end(),target);
    }

};
// @lc code=end

