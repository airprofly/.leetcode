/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    unordered_map<long long,int> prefixSumCount_;
public:
    int pathSum(TreeNode* root, int targetSum) {
        prefixSumCount_[0] = 1;
        return _pathSum(root, 0, targetSum);
    }
private: 
    int _pathSum(TreeNode* root, long long prefixSum, int targetSum){
        if (root == nullptr)return 0;
        int ret = 0;
        ret+=prefixSumCount_[prefixSum+root->val-targetSum];
        prefixSumCount_[prefixSum+root->val]++;
        prefixSum+=root->val;
        ret+=_pathSum(root->left,prefixSum,targetSum);
        ret+=_pathSum(root->right,prefixSum,targetSum);
        prefixSumCount_[prefixSum]--;
        return ret;
    }
};
// @lc code=end

