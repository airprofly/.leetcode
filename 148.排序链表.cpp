/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        vector<pair<int, ListNode *>> nodes;
        ListNode *ptr = head;
        while (ptr != nullptr)
        {
            nodes.push_back({ptr->val, ptr});
            ptr = ptr->next;
        }
        sort(nodes.begin(), nodes.end(), [](const pair<int, ListNode *> &a, const pair<int, ListNode *> &b)
             { return a.first < b.first; });
        if (nodes.empty())
            return nullptr;
        for (size_t i = 0; i + 1 < nodes.size(); ++i)
        {
            nodes[i].second->next = nodes[i + 1].second;
        }
        nodes.back().second->next = nullptr;
        return nodes[0].second;
    }
};
// @lc code=end
