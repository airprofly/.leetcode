/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> levelVals;
            while(size--){
                TreeNode* tempNode=q.front();
                q.pop();
                if(tempNode->left) q.push(tempNode->left);
                if(tempNode->left) levelVals.push_back(tempNode->left->val);
                else levelVals.push_back(INT_MIN);
                if(tempNode->right) q.push(tempNode->right);
                if(tempNode->right) levelVals.push_back(tempNode->right->val);
                else levelVals.push_back(INT_MIN);
            }
            vector<int> reversedLevelVals=levelVals;
            reverse(reversedLevelVals.begin(), reversedLevelVals.end());
            if(levelVals!=reversedLevelVals) return false;
        }
        return true;
    }
};
// @lc code=end

