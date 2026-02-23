/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxProduct(2), minProduct(2);
        maxProduct[0] = minProduct[0] = 1;
        int result = INT_MIN;
        for (int i = 1; i <= nums.size(); ++i) {
            maxProduct[i%2] = max({maxProduct[(i - 1)%2] * nums[i - 1], minProduct[(i - 1)%2] * nums[i - 1], nums[i - 1]});
            minProduct[i%2] = min({maxProduct[(i - 1)%2] * nums[i - 1], minProduct[(i - 1)%2] * nums[i - 1], nums[i - 1]});
            result = max(result, maxProduct[i%2]);    
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Solution s;
    
    vector<int> nums={2,3,-2,4};
    cout<<s.maxProduct(nums)<<endl;
    
    return 0;
}