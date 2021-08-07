#include "iostream"
#include "bits/stdc++.h"
//https://leetcode.com/problems/concatenated-words/
using namespace std;

map<string,bool>dp;
set<string> vocab;
class Solution {
public:

    bool dfs(string target,string origin_target){
//        cout  << target <<endl;

        if (target == "") return false;

        if (dp.find(target) != dp.end() and target != origin_target){
//            cout << "dp " << target << " true" <<endl;
            return dp[target];
        }

        for(int i = 1;i < target.length();i ++){
//            cout << target <<"->" << target.substr(0,i) <<" " <<target.substr(i) <<endl;
            if (vocab.count(target.substr(0,i)) and dfs(target.substr(i),origin_target)){
                dp[target] = true;
//                cout << target <<"->" << target.substr(0,i) <<" " <<target.substr(i) << "success" <<endl;
                return true;
            }

        }
        if (dp.find(target) == dp.end()){
//            cout << target <<endl;
            dp[target] = false;
        }

        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        dp.clear();vocab.clear();

        for(int i = 0;i < words.size();i ++) {
            vocab.insert(words[i]);
            dp[words[i]] = true;
        }
        vector<string> ans;ans.clear();
        for(int i = 0;i < words.size();i ++){
            if (dfs(words[i],words[i]))
                ans.push_back(words[i]);
        }
        return ans;
    }

};


