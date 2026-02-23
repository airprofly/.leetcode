/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> record;
        for(const int num:nums){
            auto lb=lower_bound(record.begin(),record.end(),num);
            if(lb==record.end()){
                record.push_back(num);
            }else{
                *lb=num;
            }
        }
        return record.size();
    }
};
// @lc code=end

