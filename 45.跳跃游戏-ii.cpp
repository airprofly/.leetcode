/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        nums[nums.size()-1]=0;
        int suffMin=0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]==0){
                nums[i]=INT_MAX;
                continue;
            }
            if(nums[i]+i>=nums.size()-1){
                nums[i]=1;
                continue;
            }
            vector<int>::iterator endIter=nums.begin()+i+nums[i]+1;
             if(i+nums[i]+1>static_cast<int>(nums.size())){
                endIter=nums.end();
            }
            int minVal=*min_element(nums.begin()+i+1,endIter);
            nums[i]=(minVal==INT_MAX)?INT_MAX:1+minVal;
        }
        return nums[0];
    }
};
// @lc code=end

