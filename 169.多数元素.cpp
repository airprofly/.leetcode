/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ret=nums[0], cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == ret){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt == 0){
                ret = nums[i];
                cnt = 1;
            }
        }
        return ret;
    }
};
// @lc code=end

