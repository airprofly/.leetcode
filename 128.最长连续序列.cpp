/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for(auto& num:nums){
            numSet.insert(num);
        }

        int maxLen=0;
        for(auto& num:numSet){
            int currentLen=1;
            if(!numSet.count(num-1)){
                int currentNum=num;
                while(numSet.count(currentNum+1)){
                    currentLen++;
                    currentNum++;
                }
            }
            maxLen=max(maxLen,currentLen);
        }
        
        return maxLen;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    freopen("./input.in","r",stdin);
    freopen("./output.out","w",stdout);
    Solution s;
    
    vector<int> nums={100,4,200,1,3,2};
    cout<<s.longestConsecutive(nums)<<endl;
    
    return 0;
}
