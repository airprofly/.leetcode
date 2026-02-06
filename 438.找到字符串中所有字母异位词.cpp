/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pLen=p.length();
        int tarVal=0;
        sort(p.begin(),p.end());
        for(auto c:p){
            tarVal+=c;
        }
        vector<int> prefixVal;
        prefixVal.reserve(s.length()+1);
        prefixVal.push_back(0);
        for(int i=0;i<pLen-1;i++){
             prefixVal.push_back(prefixVal.back()+s[i]);
        }
        vector<int> res;
        for(int i=pLen-1;i<s.length();i++){
            prefixVal.push_back(prefixVal.back()+s[i]);
            if(prefixVal.back()-prefixVal[i-pLen+1]==tarVal){
                string subStr=s.substr(i-pLen+1,pLen);
                sort(subStr.begin(),subStr.end());
                if(subStr==p)res.push_back(i-pLen+1);
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    freopen("./input.in","r",stdin);
    freopen("./output.out","w",stdout);
    Solution sol;
    
    string s="af";
    string p="be";
    vector<int> res=sol.findAnagrams(s,p);
    
    return 0;
}

