#include "iostream"
#include "bits/stdc++.h"
//https://leetcode.com/problems/concatenated-words/
using namespace std;


map<string,bool>dp;
map<string,bool>vocab;
class Solution {
public:

    bool dfs(string target,vector<string> & words,int exclude_i=-1){
        if ((vocab[target] or target == "" )and exclude_i == -1)
            return true;
        if (dp.find(target) != dp.end() and dp[target]){
            return dp[target];
        }
        for(int i = 0;i < words.size();i ++){
            string word = words[i];
            if (word.length() > target.length() or word.length() == 0 or i == exclude_i)
                continue;
            if (target.substr(0,word.length()) == word){
                  if (dfs(target.substr(word.length()),words)){
                      dp[target] = true;
                      return true;
                  }
            }
        }
        dp[target] = false;
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        dp.clear();vocab.clear();
        for(int i = 0;i < words.size();i ++) {
            vocab[words[i]] = true;
        }
        vector<string> ans;ans.clear();
        for(int i = 0;i < words.size();i ++){
            if (dfs(words[i],words,i))
                ans.push_back(words[i]);
            }
        return ans;
    }

};
