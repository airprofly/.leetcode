/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // stack<int> st;
        // int i=nums.size()-1;
        // for(;i>=0;i--){
        //     if(st.empty() || nums[i] >= nums[st.top()]){
        //         st.push(i);
        //     }else{
        //         int right;
        //         while(!st.empty() && nums[st.top()] > nums[i]){
        //             right = st.top();
        //             st.pop();
        //         }
        //         swap(nums[i], nums[right]);
        //         sort(nums.begin()+i+1, nums.end());
        //         return;
        //     }
        // }
        // reverse(nums.begin(), nums.end());
        // next_permutation(nums.begin(), nums.end());
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                swap(nums[i], *prev(lower_bound(nums.begin()+i+1, nums.end(), nums[i], greater<int>())));
                sort(nums.begin()+i+1,nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Solution s;
    vector<int> nums={1,2,3};
    s.nextPermutation(nums);
    
    return 0;
}

