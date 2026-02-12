/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */
#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) _expand(grid,i,j,2);
            }
        }

        int ret=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
                else if(grid[i][j]>=2) ret=max(ret,grid[i][j]-2);
            }
        }
        return ret;
    }
private:
    void _expand(vector<vector<int>>& grid,int i,int j,int temp){
        if(grid[i][j]==0) return;
        if(grid[i][j]>temp) {
            grid[i][j]=temp;
        }else if(grid[i][j]>2) return;

        if(grid[i][j]==1) grid[i][j]=temp;
        if(grid[i][j]==2 && temp!=2) return;

        if(i-1>=0) _expand(grid,i-1,j,temp+1);
        if(i+1<grid.size()) _expand(grid,i+1,j,temp+1);
        if(j-1>=0) _expand(grid,i,j-1,temp+1);
        if(j+1<grid[0].size()) _expand(grid,i,j+1,temp+1);
    }
};
// @lc code=end


int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Solution s;
    
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    cout<<s.orangesRotting(grid)<<endl;

    
    
    return 0;
}

