/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        _rotate90(matrix, 0, matrix.size() - 1);
    }
private:
    void _rotate90(vector<vector<int>>& matrix,const int start,const int end){
        if(start>=end)return;
        for(int i=start;i<end;i++){
            int temp=matrix[end-(i-start)][start];
            matrix[end - (i - start)][start] = matrix[end][end - (i - start)];
            matrix[end][end-(i-start)]=matrix[i][end];
            matrix[i][end]=matrix[start][i];
            matrix[start][i]=temp;
        }
        _rotate90(matrix,start+1,end-1);
    }

};
// @lc code=end

int main(int argc, char const *argv[])
{
    freopen("./input.in","r",stdin);
    freopen("./output.out","w",stdout);
    Solution s;
    
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    s.rotate(matrix);
    
    return 0;
}
