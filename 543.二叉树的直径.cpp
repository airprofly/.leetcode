/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int maxDiameter=0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        _dfs(root);
        return maxDiameter;
    }

private: 
    int _dfs(TreeNode* root){
        if(root==nullptr) return 0;
        int leftDepth=_dfs(root->left);
        int rightDepth=_dfs(root->right);
        maxDiameter=max(maxDiameter, leftDepth+rightDepth);
        return max(leftDepth, rightDepth)+1;
    }
};
// @lc code=end

