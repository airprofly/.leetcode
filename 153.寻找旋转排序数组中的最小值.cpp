/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=(left+right)>>1;
            if(nums[mid]>=nums[0]){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return min(nums[left],nums[0]);
    }
};
// @lc code=end

