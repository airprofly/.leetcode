/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        deque<int> st;
        int maxArea=0;
        vector<int> left(heights.size());
        vector<int> right(heights.size(),heights.size());

        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<=heights[st.back()]){
                right[st.back()]=i;
                st.pop_back();
            }
            left[i]=st.empty()?-1:st.back();
            st.push_back(i);
        }
        
        for(int i=0;i<heights.size();i++){
            maxArea=max(maxArea,heights[i]*(right[i]-left[i]-1));
        }
        return maxArea;
    }
}; 
// @lc code=end

int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Solution s;
    
    vector<int> heights={2,1,5,6,2,3};
    cout<<s.largestRectangleArea(heights)<<endl;
    
    return 0;
}
