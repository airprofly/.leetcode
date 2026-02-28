/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0=0, p2=nums.size()-1,curPos=0;
        while(curPos<=p2){
            if(nums[curPos] == 0){
                swap(nums[curPos], nums[p0]);
                p0++;
                curPos++;
            }else if(nums[curPos] == 2){
                swap(nums[curPos], nums[p2]);
                p2--;
            }else{
                curPos++;
            }
        }
    }
};
// @lc code=end

