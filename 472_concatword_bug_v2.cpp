#include "bits/stdc++.h"
#include "iostream"

using namespace std;
unordered_set<string> vocab;

class Solution {
public:

    bool dfs(string word,int s){
        if (s == word.size()) return true;
        for(int i = s;i < word.size();i ++){
            if (vocab.find(word.substr(s,i-s+1))!=vocab.end() and i-s+1 != word.length() and dfs(word,i+1))
                return true;
        }
        return false;
    }


    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vocab.clear();
        for(string s : words){
            vocab.insert(s);
        }
        vector<string> ans;ans.clear();
        for(string s:words){
            if (s.length() > 0 and dfs(s,0)){
                ans.push_back(s);
            }
        }
        return ans;
    }
};