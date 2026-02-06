/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxPrefixSum=INT_MIN;
        int tempPrefixSum=0;
        int minPrefixSum=0;
        int existPositive=false;
        for(int i=0;i<nums.size();i++){
            tempPrefixSum+=nums[i];
            int prevMinPrefixSum= minPrefixSum;
            minPrefixSum=min(minPrefixSum,tempPrefixSum);
            if(nums[i]>0)existPositive=true;
            if(nums[i]<=0 && existPositive)continue;
            maxPrefixSum=max(maxPrefixSum,tempPrefixSum - prevMinPrefixSum);
        }
        return maxPrefixSum;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    freopen("./input.in","r",stdin);
    freopen("./output.out","w",stdout);
    Solution s;
    
    vector<int> nums={-1};
    cout<<s.maxSubArray(nums)<<endl;
    
    return 0;
}

