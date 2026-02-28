/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(), start=0, max_len=1;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j] && (j-i<3 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(j-i+1>=max_len){
                        max_len=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
};
// @lc code=end


int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Solution s;
    
    s.longestPalindrome("cbbd");
    
    return 0;
}
