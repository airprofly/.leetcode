/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ret+=_visit(grid,i,j);
            }
        }
        return ret;
    }
private:
    int _visit(vector<vector<char>>& grid,int i,int j){
        if(grid[i][j]=='2'||grid[i][j]=='0') return 0;
        grid[i][j]='2';
        if(i-1>=0&&grid[i-1][j]=='1') _visit(grid,i-1,j);
        if(i+1<grid.size()&&grid[i+1][j]=='1') _visit(grid,i+1,j);
        if(j-1>=0&&grid[i][j-1]=='1') _visit(grid,i,j-1);
        if(j+1<grid[0].size()&&grid[i][j+1]=='1') _visit(grid,i,j+1);
        return 1;
    }
};
// @lc code=end

