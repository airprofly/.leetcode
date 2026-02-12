/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);   
    }

private: 
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int preorderLeft, int preorderRight, int inorderLeft, int inorderRight){
        if(preorderLeft>preorderRight) return nullptr;
        int rootVal = preorder[preorderLeft];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndexInorder = -1;
        for(int i=inorderLeft;i<=inorderRight;i++){
            if(inorder[i]==rootVal){
                rootIndexInorder = i;
                break;
            }
        }
        int leftTreeSize = rootIndexInorder - inorderLeft;
        root->left = _buildTree(preorder,inorder,preorderLeft+1,preorderLeft+leftTreeSize,inorderLeft,rootIndexInorder-1);
        root->right = _buildTree(preorder,inorder,preorderLeft+leftTreeSize+1,preorderRight,rootIndexInorder+1,inorderRight);
        return root;
    }
};
// @lc code=end

