/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        int len=0;
        ListNode* curr=head;
        while(curr!=nullptr){
            len++;
            curr=curr->next;
        }
        int half=len/2;
        int odd=len&1;
        curr=head;
        ListNode* prev=nullptr;
        for(int i=0;i<half;i++){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        ListNode* leftCurr=prev;
        ListNode* rightCurr=odd?curr->next:curr;
        while(leftCurr!=nullptr&&rightCurr!=nullptr){
            if(leftCurr->val!=rightCurr->val){
                return false;
            }
            leftCurr=leftCurr->next;
            rightCurr=rightCurr->next;
        }
        return true;
    }
};
// @lc code=end

