/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int x=0,y=matrix[0].size()-1;
        while(matrix[x][y]!=target){
            if(matrix[x][y]>target){
                y--;
            }else{
                x++;
            }
            if(x>=matrix.size()||y<0){
                return false;
            }
        }
        return true;

        // return _search(matrix, target, 0, matrix.size(), 0, matrix[0].size());
    }

private:
    bool _search(const vector<vector<int>> &matrix, int target, int top, int bottom, int left, int right)
    {
        if (left >= right || top >= bottom)
            return false;
        if (left + 1 == right && top + 1 == bottom)
        {
            return matrix[top][left] == target;
        }
        auto ub = upper_bound(matrix[top].begin() + left, matrix[top].begin() + right, target);
        right = distance(matrix[top].begin(), ub);
        if (right == left)
            return false;
        if (matrix[top][right - 1] == target)
            return true;

        auto row_ub = upper_bound(matrix.begin() + top, matrix.begin() + bottom, target, [&](int val, const vector<int> &row)
                                  { return val < row[left]; });
        bottom = distance(matrix.begin(), row_ub);
        if (bottom == top)
            return false;
        if (matrix[bottom - 1][left] == target)
            return true;

        auto row_tb = lower_bound(matrix.begin() + top, matrix.begin() + bottom, target, [&](const vector<int> &row, int val)
                                  { return row[right - 1] < val; });
        if (row_tb == matrix.begin() + bottom)
            return false;
        if ((*row_tb)[right - 1] == target)
            return true;
        top = distance(matrix.begin(), row_tb);

        auto col_lb = lower_bound(matrix[bottom - 1].begin() + left, matrix[bottom - 1].begin() + right, target);
        if (col_lb == matrix[bottom-1].begin() + right)
            return false;
        if (*col_lb == target)
            return true;
        left = distance(matrix[bottom - 1].begin(), col_lb);

        return _search(matrix, target, top, bottom, left, right);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Solution s;

    // vector<vector<int>> matrix = {
    //     {3, 6, 9, 12, 17, 22},
    //     {5, 11, 11, 16, 22, 26},
    //     {10, 11, 14, 16, 24, 31},
    //     {10, 15, 17, 17, 29, 31},
    //     {14, 17, 20, 23, 34, 37},
    //     {19, 21, 22, 28, 37, 40},
    //     {22, 22, 24, 32, 37, 43}};
    vector<vector<int>> matrix = {
        {1, 3, 5, 7, 9},
        {2, 4, 6, 8, 10},
        {11, 13, 15, 17, 19},
        {12, 14, 16, 18, 20},
        {21, 22, 23, 24, 25}};
    int target = 13;
    bool result = s.searchMatrix(matrix, target);
    printf("%s\n", result ? "true" : "false");

    return 0;
}
