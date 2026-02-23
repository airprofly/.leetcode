/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class MedianFinder {
private:
    priority_queue<int> max_heap_;
    priority_queue<int, vector<int>, greater<int>> min_heap_;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap_.empty() || num <= max_heap_.top()) {
            max_heap_.push(num);
            if(max_heap_.size() > min_heap_.size() + 1) {
                min_heap_.push(max_heap_.top());
                max_heap_.pop();
            }
        }else{
            min_heap_.push(num);
            if(min_heap_.size() > max_heap_.size()) {
                max_heap_.push(min_heap_.top());
                min_heap_.pop();
            }
        }   
    }
    
    double findMedian() {
        if(max_heap_.size() > min_heap_.size()) {
            return max_heap_.top();
        } else {
            return (max_heap_.top() + min_heap_.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

