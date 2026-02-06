/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tMap;
        for(auto c:t){
            tMap[c]++;
        }
        int minLen=INT_MAX;
        int left=-1;
        deque<int> points;
        char expectedChar='\0';
        bool firstTime=true;
        for(int i=0;i<s.length();i++){
            if(tMap.find(s[i])==tMap.end())continue;
            points.push_back(i);
            tMap[s[i]]--;
            if(!firstTime){
                if(s[i]!=expectedChar){
                    continue;
                }
            }
            bool valid = true;
            for(auto &p:tMap){
                if(p.second>0){
                    valid=false;
                    break;
                }
            }
            if(!valid)continue;
            firstTime=false;
            int tempLen=i-points.front()+1;
            int leftIndex=points.front();
            int tempChar=s[points.front()];
            points.pop_front();
            tMap[tempChar]++;
            while(tMap[tempChar]<=0){
                leftIndex=points.front();
                tempChar=s[points.front()];
                points.pop_front();
                tMap[tempChar]++;
                tempLen=i-leftIndex+1;
            }
            expectedChar=tempChar;
            if(tempLen<minLen){
                minLen=tempLen;
                left=leftIndex;
            }
        }
        return left==-1?"":s.substr(left,minLen);
    }
    
};
// @lc code=end


int main(int argc, char const *argv[])
{
    freopen("./input.in","r",stdin);
    freopen("./output.out","w",stdout);
    Solution s;
    
    cout<<s.minWindow("ADOBECODEBANC","ABC")<<endl;
    
    return 0;
}
