/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator zeroIt=nums.begin();
        while(zeroIt!=nums.end() && *zeroIt!=0){
            ++zeroIt;
        }
        vector<int>::iterator nonZeroIt=zeroIt;
        while(nonZeroIt!=nums.end() && *nonZeroIt==0){
            ++nonZeroIt;
        }

        while(nonZeroIt!=nums.end()){
            swap(*zeroIt,*nonZeroIt);
            ++zeroIt;
            while(zeroIt!=nums.end() && *zeroIt!=0){
                ++zeroIt;
            }
            ++nonZeroIt;
            while(nonZeroIt!=nums.end() && *nonZeroIt==0){
                ++nonZeroIt;
            }
        }
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    freopen("./input.in","r",stdin);
    freopen("./output.out","w",stdout);
    Solution s;
    
    vector<int> nums={0,1,0,3,12};
    s.moveZeroes(nums);
    
    return 0;
}