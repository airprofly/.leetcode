/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
    static unordered_map<Node*,Node*> visitedHash;
     
public:
    Node* copyRandomList(Node* head) {
        Node* ret=_cloneList(head);
        Node* temp=ret;
        while(temp!=nullptr){
            if(head->random!=nullptr){
                temp->random=visitedHash[head->random];
            }else{
                temp->random=nullptr;
            }
            head=head->next;
            temp=temp->next;
        }
        return ret;
    }

    Node* _cloneList(Node* head){
        if (head == nullptr)
            return nullptr;
        Node *currPtr = new Node(head->val);
        visitedHash[head] = currPtr;
        currPtr->next = _cloneList(head->next);
        return currPtr;
    }
};

unordered_map<Node*,Node*> Solution::visitedHash;
// @lc code=end

int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    
    
    Solution s;

    
    return 0;
}

