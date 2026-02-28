/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        bitset<100001> bs;
        for (int i = 0; i < nums.size(); i++)
        {
            if (bs.test(nums[i]))
            {
                return nums[i];
            }
            else
            {
                bs.set(nums[i]);
            }
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Solution s;

    bitset<3> bs(string("101"));
    cout<<bs.to_string()<<endl;
    cout<<bs.to_ulong()<<endl;

    return 0;
}
