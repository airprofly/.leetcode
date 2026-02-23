/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
private:
    unordered_set<int> valSet;
public:
    bool canPartition(vector<int>& nums) {
        valSet.insert(0);
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2!=0) return false;
        int target=totalSum/2;
        return _dfs(nums,0,target);
    }
private:
    bool _dfs(const vector<int>& nums,int index,int target){
        if(index>=nums.size()) return false;
        unordered_set<int> tempSet=valSet;
        for(const int val:tempSet){
            int temp=val+nums[index];
            if(temp==target) return true;
            if(valSet.count(temp))continue;
            valSet.insert(temp);
        }
        return _dfs(nums,index+1,target);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Solution s;
    
    vector<int> nums={3,3,6,8,16,16,16,18,20};
    cout<<s.canPartition(nums)<<endl;
    
    return 0;
}
 