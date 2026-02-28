/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

#include<bits/stdc++.h>
using namespace std;

 
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // bitset<60002> bits;
        // for(int i:nums){
        //     bits[i+30000] = !bits[i+30000];
        // }
        // return bits._Find_first() - 30000;
        int ret=0;
        for(int i:nums){
            ret ^= i;
        }
        return ret;
    }
};
// @lc code=end

