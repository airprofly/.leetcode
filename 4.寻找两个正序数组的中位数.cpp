/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int k=(m+n+1)/2;
        if((m+n)%2==1){
            return _findMedian(nums1,0,m-1,nums2,0,n-1,k);
        }else{
            double a=_findMedian(nums1,0,m-1,nums2,0,n-1,k);
            double b=_findMedian(nums1,0,m-1,nums2,0,n-1,k+1);
            return (a+b)/2;
        }
    }
private:
    double _findMedian(const vector<int>& nums1,const int nums1left,const int nums1right,const vector<int>& nums2,const int nums2left,const int nums2right,const int k){
        if(k<=0) return 0;
        if(nums1left>nums1right) return nums2[nums2left+k-1];
        if(nums2left>nums2right) return nums1[nums1left+k-1];
        if(k==1) return min(nums1[nums1left],nums2[nums2left]);
        int nums1mid=min(nums1right,nums1left+k/2-1);
        int nums2mid=min(nums2right,nums2left+k/2-1);
        if(nums1[nums1mid]<nums2[nums2mid]){
            return _findMedian(nums1,nums1mid+1,nums1right,nums2,nums2left,nums2right,k-(nums1mid-nums1left+1));
        }else{
            return _findMedian(nums1,nums1left,nums1right,nums2,nums2mid+1,nums2right,k-(nums2mid-nums2left+1));
        }
    }
};
// @lc code=end

