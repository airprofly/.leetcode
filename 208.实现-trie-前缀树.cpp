/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Trie {
private:
    struct TrieNode_{
        bool isEnd;
        vector<TrieNode_*> next;
        TrieNode_():isEnd(false),next(26,nullptr){}
    };
    TrieNode_* root_;

public:
    Trie() {
        root_ = new TrieNode_();
    }
    
    void insert(string word) {
        insert_(root_, word);
    }
    
    bool search(string word) {
        TrieNode_* root=this->root_;
        for(const char& c:word){
            if(root->next[c-'a']==nullptr) return false;
            root=root->next[c-'a'];
        }
        return root->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode_* root=this->root_;
        for(const char& c:prefix){
            if(root->next[c-'a']==nullptr) return false;
            root=root->next[c-'a'];
        }
        return true;
    }
private:
    void insert_(TrieNode_* root,string& word){
        if(word.empty())return;
        char c=word[0];
        if(root->next[c-'a']==nullptr) {
            root->next[c-'a']=new TrieNode_();
        }
        word.erase(word.begin(),word.begin()+1);
        if(word.empty()){
            root->next[c-'a']->isEnd=true;
            return;
        }
        insert_(root->next[c-'a'],word);
        return;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

int main(int argc, char const *argv[])
{
    // freopen("./input.in","r",stdin);
    // freopen("./output.out","w",stdout);
    Trie s;
    
    s.insert("apple");
    cout<<s.search("apple")<<endl;
    cout<<s.search("app")<<endl;
    cout<<s.startsWith("app")<<endl;
    
    return 0;
}
