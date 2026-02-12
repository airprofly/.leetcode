/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
public:
    bool isValidBST(TreeNode* root) {
        return _isValidBST(root, LLONG_MIN, LLONG_MAX);
    }   
private:
    bool _isValidBST(TreeNode* root, long long lb,long long ub){
        if(root==nullptr) return true;
        if(root->left&&(root->left->val<=lb || root->left->val>=root->val)) return false;
        if(root->right&&(root->right->val<=root->val || root->right->val>=ub)) return false;
        return _isValidBST(root->left,lb,root->val) && _isValidBST(root->right,root->val,ub);
    }
};
// @lc code=end

