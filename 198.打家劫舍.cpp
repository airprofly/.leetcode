/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        nums.push_back(0);
        nums.push_back(0);
        for(int i=nums.size()-3;i>=0;i--){
            nums[i]=max(nums[i+1],nums[i]+nums[i+2]);
        }
        return nums[0];
    }
};
// @lc code=end

