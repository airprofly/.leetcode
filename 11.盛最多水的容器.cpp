/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
    //     map<int,int,greater<int>> heightIndexMap;
    //     int maxArea=INT_MIN;
    //     heightIndexMap.insert({height[0],0});
    //     for(int i=1;i<height.size();i++){
    //         int tempHeight=height[i];
    //         for(auto& [h,index]:heightIndexMap){
    //             if(min(h,tempHeight)*i<maxArea){
    //                 break;
    //             }
    //             int area=min(h,tempHeight)*(i-index);
    //             maxArea=max(maxArea,area);
    //         }
    //         heightIndexMap.insert({tempHeight, i});
    //     }
    //     return maxArea;
    // }
        vector<int>::iterator lit=height.begin();
        vector<int>::iterator rit=height.end()-1;
        int maxArea=INT_MIN;
        while(lit<rit){
            int tempHeight=min(*lit,*rit);
            int tempArea=min(*lit,*rit)*(rit-lit);
            maxArea=max(maxArea,tempArea);

            while(*lit<=tempHeight && lit<rit){
                lit++;
            }
            while(*rit<=tempHeight && lit<rit){
                rit--;
            }
        }
        return maxArea;
    }
    
};
// @lc code=end

