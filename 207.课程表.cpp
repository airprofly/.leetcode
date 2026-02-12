/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
// private: 
//     vector<vector<int>> graph_;
//     vector<int> visited_; // 0:not visit, 1:visited , 2 : no cycle 
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         graph_.resize(numCourses);
//         for(auto& p:prerequisites){
//             graph_[p[1]].push_back(p[0]);
//         }
//         visited_.resize(numCourses);
//         for(int i=0;i<numCourses;i++){
//             if(!_dfs(i)) return false;
//         }                              
//         return true;
//     }

// private:
//     bool _dfs(int id){
//         if(graph_[id].empty()) 
//         {
//             visited_[id]=2;
//             return true;
//         }
//         if(visited_[id]==1) return false;
//         if(visited_[id]==2) return true;
//         visited_[id]=1;
//         for(auto& next:graph_[id]){
//             bool ret=_dfs(next);
//             if(!ret) return false;
//         }
//         visited_[id]=2;
//         return true;
//     }

private: 
    vector<vector<int>> graph_;
    vector<int> inDegree_;
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph_.resize(numCourses);
        inDegree_.resize(numCourses, 0);

        for(const auto& p:prerequisites){
            graph_[p[1]].push_back(p[0]);
            inDegree_[p[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree_[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            numCourses--;
            for(const auto& neighbor: graph_[node]){
                inDegree_[neighbor]--;
                if(inDegree_[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        
        return numCourses==0;
    }
};
// @lc code=end

