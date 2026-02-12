/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

 #include<bits/stdc++.h>
 using namespace std;
 

// @lc code=start
class LRUCache {
private:
    int capacity_;
    list<pair<int,int>> keyValsQueue_;
    unordered_map<int,list<pair<int,int>>::iterator> keyIterators_;
public:
    LRUCache(int capacity): capacity_(capacity){
        
    }
    
    int get(int key) {
        if(keyIterators_.find(key) == keyIterators_.end()){
            return -1;
        }
        keyValsQueue_.splice(keyValsQueue_.end(), keyValsQueue_, keyIterators_[key]);
        return keyIterators_[key]->second;
    }

    void put(int key, int value) {
        if(keyIterators_.find(key) != keyIterators_.end()){
            keyValsQueue_.splice(keyValsQueue_.end(), keyValsQueue_, keyIterators_[key]);
            keyIterators_[key]->second = value;
            return;
        }
        if(keyValsQueue_.size() == capacity_){
            auto pairToRemove = keyValsQueue_.front();
            keyValsQueue_.pop_front();
            keyIterators_.erase(pairToRemove.first);
        }
        keyValsQueue_.push_back({key, value});
        keyIterators_[key] = prev(keyValsQueue_.end());
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

