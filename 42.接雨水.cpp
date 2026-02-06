/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // stack<int> st;
        // int ret=0;
        // for(int i=0;i<height.size();i++){
        //     while(!st.empty() && height[i]>height[st.top()]){
        //         int tempIndex=st.top();
        //         st.pop();
        //         if(st.empty())break;
        //         int width=i-st.top()-1;
        //         int h=min(height[i],height[st.top()])-height[tempIndex];
        //         ret+=width*h;
        //     }
        //     st.push(i);
        // }
        // return ret;

        int ret=0;
        vector<int>::iterator lit=height.begin();
        vector<int>::iterator rit=height.end()-1;
        int leftMax=INT_MIN, rightMax=INT_MIN;
        while(lit<rit){
            if(*lit<=*rit){
                leftMax=max(leftMax,*lit);
                if(*(lit+1)<leftMax){
                    ret+=leftMax-*(lit+1);
                }
                lit++;
            }else{
                rightMax=max(rightMax,*rit);
                if(*(rit-1)<rightMax){
                    ret+=rightMax-*(rit-1);
                }
                rit--;
            }
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
    
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(height)<<endl;
    
    return 0;
}
