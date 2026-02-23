/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */


#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return vector<int>{-1,-1};
        vector<int>::iterator it= lower_bound(nums.begin(),nums.end(),target);
        if(it==nums.end() || *it!=target) return vector<int>{-1,-1};
        int left=it-nums.begin();
        vector<int>::iterator it2= upper_bound(nums.begin(),nums.end(),target);
        int right=it2-nums.begin()-1;
        return vector<int>{left,right};
    }
};
// @lc code=end

