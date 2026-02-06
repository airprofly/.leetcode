/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除了自身以外数组的乘积
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProducts(nums.size(),1);
        vector<int> suffixProducts(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            prefixProducts[i]=prefixProducts[i-1]*nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            suffixProducts[i]=suffixProducts[i+1]*nums[i+1];
        }
        vector<int> result(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            result[i]=prefixProducts[i]*suffixProducts[i];
        }
        return result;
    }
};
// @lc code=end

