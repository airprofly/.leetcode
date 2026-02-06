/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> indices;
        for(int i=0;i<nums.size();i++){
            int partner=target-nums[i];
            if(indices.find(partner)!=indices.end()){
                return {indices[partner],i};
            }
            indices.insert({nums[i],i});
        }
        return {};
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    freopen("./input.in","r",stdin);
    freopen("./output.out","w",stdout);
    Solution s;
    
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> res=s.twoSum(nums,target);
    for(auto num:res){
        cout<<num<<" ";
    }
    cout<<endl;
    
    return 0;
}

