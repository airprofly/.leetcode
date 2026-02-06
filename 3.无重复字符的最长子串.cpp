/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> char_indices;
        int max_len=0;
        int temp_len=0;
        int prev_index=-1;
        bool update_flag=false;
        for(int i=0;i<s.length()&&(s.length()-prev_index>max_len);i++)
        {
            char temp=s[i];
            if(char_indices.find(temp)==char_indices.end()|| char_indices[temp]<prev_index){
                temp_len++;
                char_indices[temp]=i; 
            }else{
                max_len=max(max_len,temp_len);
                prev_index=char_indices[temp];
                temp_len=i -char_indices[temp];
                update_flag=true;
                char_indices[temp]=i;
            }
        }
        return max(temp_len, max_len);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    freopen("./input.in","r",stdin);
    freopen("./output.out","w",stdout);
    Solution s;
    
    string str="abba";
    int res=s.lengthOfLongestSubstring(str);
    cout<<res<<endl;
    
    return 0;
}

