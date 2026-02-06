// /*
//  * @lc app=leetcode.cn id=2 lang=cpp
//  *
//  * [2] 两数相加
//  */

// #include<bits/stdc++.h>
// using namespace std;


// // @lc code=start
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int carry=0;
//         ListNode* l1_start=l1;
//         ListNode* l2_start=l2;
//         ListNode* ret=nullptr;
//         ListNode* prev=nullptr;
//         while(l1!=nullptr || l2!=nullptr || carry!=0){
//             if(l1!=nullptr &&l2!=nullptr){
//                 l1->val+=l2->val+carry;
//                 carry=l1->val/10;
//                 l1->val=l1->val%10;
//                 l2->val=l1->val;
                
//                 ret=l1_start;
//                 prev=l1;
                
//                 l1=l1->next;
//                 l2=l2->next;
//             }else if(l1==nullptr && l2!=nullptr){
//                 l2->val+=carry;
//                 carry=l2->val/10;
//                 l2->val=l2->val%10;
//                 ret=l2_start;
//                 prev=l2;

//                 l2=l2->next;
//             }else if(l1!=nullptr && l2==nullptr){
//                 l1->val+=carry;
//                 carry=l1->val/10;
//                 l1->val=l1->val%10;
//                 ret=l1_start;
//                 prev=l1;
                
//                 l1=l1->next;
//             }else{
//                 ListNode* newNode=new ListNode(carry);
//                 carry=0;
//                 prev->next=newNode;
//             }
            
//         }

//         return ret;
//     }
// };
// // @lc code=end

