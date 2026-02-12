/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
private: 
    vector<vector<int>> ret_;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        _permute(nums,0);
        return ret_;
    }

private:
    void _permute(vector<int>& nums,int left){
        if(left>=nums.size()){
            ret_.push_back(nums);
            return;
        }
        for(int i=left;i<nums.size();i++){
            swap(nums[left],nums[i]);
            _permute(nums,left+1);
            swap(nums[left],nums[i]);
        }
        return;
    }
};
// @lc code=end

