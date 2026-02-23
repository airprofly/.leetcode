/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

#include<bits/stdc++.h>
using namespace std;

 
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return _search(nums,target,0,nums.size()-1);   
    }

private:
    int _search(const vector<int>& nums,const int target,int left,int right){
        if(nums.empty()|| left>right) return -1;
        while(left<=right){
            int mid=(left+right)>>1;
            if(nums[mid]==target)return mid;
            if(nums[0]<=nums[mid]){// mid 在左边
                if(nums[0]<=target && target<nums[mid]) right=mid-1;
                else left=mid+1;
            }else{// mid 在右边
                if(nums[mid]<target && target<=nums.back()) left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
    }
};
// @lc code=end

