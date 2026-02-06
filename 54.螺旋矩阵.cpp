/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        auto tit=matrix.begin();
        auto bit=matrix.end();
        int lit=0;
        int rit=matrix[0].size();
        vector<int> ret;
        while(lit<rit||tit<bit){
            // left -> right
            ret.insert(ret.end(),next((*tit).begin(),lit),next((*tit).begin(),rit));
            tit++;
            if(tit==bit)break;
            // top -> bottom
            for(auto it=tit;it!=bit;it++){
                ret.push_back((*it)[rit-1]);
            }
            rit--;
            if(rit<=lit) break;
            // right -> left            
            bit--;
            ret.insert(ret.end(),next((*bit).rbegin(),matrix[0].size()-rit),prev((*bit).rend(),lit));
            if(bit==tit) break;
            // bottom -> top
            for(auto it=bit-1;distance(matrix.begin(),it)>=distance(matrix.begin(),tit);it--){
                ret.push_back((*it)[lit]);
            }
            lit++;
            if(lit>=rit) break;
        }
        return ret;
    }
};
// @lc code=end


int main(int argc, char const *argv[])
{
    freopen("./input.in","r",stdin);
    freopen("./output.out","w",stdout);
    Solution s;
    
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    vector<int> result = s.spiralOrder(matrix);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}