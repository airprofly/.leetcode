/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum_ = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        _maxPathSum(root,0,0);
        return maxPathSum_;
    }
private: 
    int _maxPathSum(TreeNode* root,int minPathSum,int prePathSum){
        if(root==nullptr) return prePathSum;
        prePathSum+=root->val;
        maxPathSum_=max(maxPathSum_,prePathSum-minPathSum);
        minPathSum = min(minPathSum,prePathSum);
        int leftMaxPathSum = _maxPathSum(root->left,minPathSum,prePathSum);
        int rightMaxPathSum = _maxPathSum(root->right,minPathSum,prePathSum);
        int ret=max(leftMaxPathSum,rightMaxPathSum);
        ret=max(ret,prePathSum);
        maxPathSum_=max(maxPathSum_,leftMaxPathSum-prePathSum+rightMaxPathSum-prePathSum+root->val);
        return ret;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Solution s;
    
    
    return 0;
}
