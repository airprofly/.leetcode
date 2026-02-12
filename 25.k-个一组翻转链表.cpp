/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=k;
        ListNode* ptr=head;
        while(ptr!=nullptr&&cnt--){
            ptr=ptr->next;
        }
        if(cnt>0)return head;
        ListNode* sonPtr=ptr;
        ListNode* prevPtr=head;
        ListNode* currPtr=head->next;
        cnt=k-1;
        while(cnt--){
            ListNode* temp=currPtr->next;
            currPtr->next=prevPtr;
            prevPtr=currPtr;
            currPtr=temp;
        }
        head->next=reverseKGroup(sonPtr,k);
        return prevPtr;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Solution s;
    
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);

    int k=2;
    ListNode* res=s.reverseKGroup(head,k);
    
    
    return 0;
}

