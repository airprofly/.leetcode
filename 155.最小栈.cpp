/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class MinStack {
private:
    deque<int> stack;
    deque<int> minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        stack.push_back(val);
        if(minStack.empty() || val<=minStack.back()){
            minStack.push_back(val);
        }else{
            minStack.push_back(minStack.back());
        }
    }
    
    void pop() {
        if(!stack.empty()){
            stack.pop_back();
            minStack.pop_back();
        }
    }
    
    int top() {
        if(!stack.empty()){
            return stack.back();
        }
        return 0;
    }
    
    int getMin() {
        if(!minStack.empty()){
            return minStack.back();
        }
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

