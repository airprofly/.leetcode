/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rowSet;
        unordered_set<int> colSet;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rowSet.insert(i);
                    colSet.insert(j);
                }
            }
        }
        for(int i=0;i<m;i++){
            if(rowSet.find(i)!=rowSet.end()){
                fill(matrix[i].begin(),matrix[i].end(),0);
            }
        }
        for(int j=0;j<n;j++){
            if(colSet.find(j)!=colSet.end()){
                for(int i=0;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
// @lc code=end

