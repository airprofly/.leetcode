/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        hashMap[0]++;
        nums.insert(nums.begin(),0);
        int ret=0;
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
           if(hashMap.count(nums[i]-k)){
               ret+=hashMap[nums[i]-k];
           }
           hashMap[nums[i]]++;
        }
        return ret;
    }
};
// @lc code=end


int main(int argc, char const *argv[])
{
    freopen("./input.in","r",stdin);
    freopen("./output.out","w",stdout);
    Solution s;
    
    vector<int> nums={-1,-1,1};
    int k=0;

    int res=s.subarraySum(nums,k);
    cout << res << endl;
    return 0;
}

