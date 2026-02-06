/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include<bits/stdc++.h>
using namespace std;
 

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> st;
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&nums[st.back()]<=nums[i]){
                st.pop_back();
            }
            st.push_back(i);
            if(i<k-1)continue;
            vector<int>::iterator it=lower_bound(st.begin(),st.end(),i-k+1);
            ret.push_back(nums[*it]);
            // st.erase(st.begin(),it);
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
    
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> res=s.maxSlidingWindow(nums,k);
    
    return 0;
}
