/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq_map;
        for(const int num:nums){
            freq_map[num]++;
        }
        vector<pair<int,int>> freq_vec(freq_map.begin(),freq_map.end());
        nth_element(freq_vec.begin(), freq_vec.end() - k, freq_vec.end(),
                    [](const pair<int,int>& a,const pair<int,int>& b){
                        return a.second < b.second;
                    });
        vector<int> ret;
        for(int i=freq_vec.size()-k;i<freq_vec.size();i++){
            ret.emplace_back(freq_vec[i].first);    
        }
        return ret;
    }
};
// @lc code=end

