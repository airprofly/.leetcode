/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
private: 
    vector<vector<int>> ret_;
    vector<int> path_;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        _combinationSum(candidates,target,0);
        return ret_;
    }
private:
    void _combinationSum(vector<int>& candidates,int target,int index){
        if(target==0){
            ret_.push_back(path_);
            return;
        }
        if(candidates.empty()||index>=candidates.size()||target<candidates[index]) return;
        _combinationSum(candidates,target,index+1);
        path_.push_back(candidates[index]);
        _combinationSum(candidates,target-candidates[index],index);
        path_.pop_back();
        return;
    }
};
// @lc code=end

