/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr){}  
    ListNode(int x) : val(x), next(nullptr){}  
    ListNode(int x, ListNode *next) : val(x), next(next){}
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;   
        for(auto node:lists){
            if(node!=nullptr){
                pq.push({node->val,node});
            }
        }
        ListNode* dummyHead=new ListNode(-1);
        ListNode* ptr=dummyHead;
        while(!pq.empty()){
            auto [val,node]=pq.top();
            pq.pop();
            ptr->next=node;
            ptr=ptr->next;
            if(node->next!=nullptr){
                pq.push({node->next->val,node->next});
            }
        }
        ListNode* temp=dummyHead->next;
        delete dummyHead;
        return temp;
    }
};
// @lc code=end

