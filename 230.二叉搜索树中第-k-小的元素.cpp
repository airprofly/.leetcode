/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        _findKthSmallest(root, k, res);
        return res;
    }
private:
    int _findKthSmallest(TreeNode* root, int k, int& res){
        if(root==nullptr) return 0;
        int cnt=0;
        cnt+=_findKthSmallest(root->left, k, res);
        if(cnt>=k) return cnt;
        cnt++;
        if(cnt>=k){
            res=root->val;
            return cnt;
        }
        cnt+=_findKthSmallest(root->right, k-cnt, res);
        return cnt;
    }
};
// @lc code=end

