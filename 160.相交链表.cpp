/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> nodes_in_B;
        while(headB != NULL)
        {
            nodes_in_B.insert(headB);
            headB = headB->next;
        }
        while(headA != NULL)
        {
            if(nodes_in_B.find(headA) != nodes_in_B.end())
                return headA;
            headA = headA->next;
        }
        return NULL;
    }
};
// @lc code=end

