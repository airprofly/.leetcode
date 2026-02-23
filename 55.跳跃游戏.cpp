/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currIdx=0;
        int maxJump=0;
        while(currIdx<=maxJump){
            maxJump=max(maxJump,currIdx+nums[currIdx]);
            if(maxJump>=nums.size()-1){
                return true;
            }
            currIdx++;
        }
        return false;
    }
};
// @lc code=end

