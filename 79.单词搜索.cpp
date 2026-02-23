/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(_exist(board,word,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool _exist(vector<vector<char>>& board,string& word,const int i,const int j){
        if (word.empty())
        {
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()){
            return false;
        }
        if(board[i][j]!=word[0] || board[i][j]=='#'){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='#'; //标记为已访问
        word.erase(word.begin());
        bool ret=false;
        ret=_exist(board,word,i+1,j) || _exist(board,word,i-1,j) || _exist(board,word,i,j+1) || _exist(board,word,i,j-1);
        word.insert(word.begin(),temp);
        board[i][j]=temp; //恢复原值
        return ret;
    }
};
// @lc code=end

