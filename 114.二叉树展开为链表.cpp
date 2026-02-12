/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        _flatten(root);
    }
private:
    TreeNode* _flatten(TreeNode* root){
        if(root==nullptr) return nullptr;
        TreeNode* lastNode = root;
        if(root->left){
            lastNode = _flatten(root->left);
            if(root->right) lastNode->right = root->right;
            root->right=root->left;
            root->left = nullptr;
        }
        if(lastNode->right){
            return _flatten(lastNode->right);
        }else{
            return lastNode;
        }
    }

};
// @lc code=end

