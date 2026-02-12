/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
private: 
    vector<vector<int>> ret_;
    vector<int> path_; 

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        _subsets(nums,0);
        return ret_;
    }
private:
    void _subsets(vector<int>& nums,int index){
        if(index>=nums.size()){
            ret_.push_back(path_);
            return;
        }
        _subsets(nums,index+1);
        path_.push_back(nums[index]);
        _subsets(nums,index+1);
        path_.pop_back();
        return;
    }
};
// @lc code=end

