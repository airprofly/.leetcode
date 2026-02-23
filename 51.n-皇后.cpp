/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
private: 
    vector<vector<string>> res;

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path;
        path.assign(n,string(n,'Q'));
        _dfs(path,0,n);
        return res;
    }
private:
    void _dfs(vector<string>map,const int curRow,const int n){
        if(curRow<0) return;
        if(curRow>=n){
            res.push_back(map);
            return;
        }
        for(int i=0;i<n;i++){
            if(map[curRow][i]!='Q') continue;
            vector<string> newMap=map;
            _markRow(newMap,curRow,i);
            _markCol(newMap,curRow,i);
            _markDiag(newMap,curRow,i);
            newMap[curRow][i]='Q';
            _dfs(newMap,curRow+1,n);
        }
    }

    void _markRow(vector<string>& map, const int i,const int j){
        string curRow=string(map[i].size(),'.');
        map[i]=curRow;
        return;
    }

    void _markCol(vector<string>& map, const int i,const int j){
        for(int k=i+1;k<map.size();k++){
            map[k][j]='.';
        }
        return;
    }

    void _markDiag(vector<string>& map, const int i,const int j){
        for(int k = 1; k <= std::max(static_cast<int>(map.size()) - i, i ); k++){
            if(i + k < map.size()  && j - k >= 0) map[i + k][j - k] = '.';
            if(i + k < map.size() && j + k < map.size()) map[i + k][j + k] = '.';
        }
        return; 
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Solution s;
    
    s.solveNQueens(4);
    
    return 0;
}

