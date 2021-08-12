#include "bits/stdc++.h"
#include "iostream"

using namespace std;
unordered_map<string,bool>dp;
unordered_set<string> vocab;
int cnt=0;
class Solution {
public:

    bool dfs(string target,string origin_target){
        // cout  << target <<endl;

        if (target == "") return false;

        if (dp.find(target) != dp.end() and target != origin_target){
//            cout << "dp " << target << " true" <<endl;
            // cout << target << " " << dp[target] << endl;
            return dp[target];
        }

        for(int i = 1;i < target.length();i ++){
            cnt += 1;
            // cout << target <<"->" << target.substr(0,i) <<" " <<target.substr(i) <<endl;
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
            // cout << "i:" << i << endl;
            if (dfs(words[i],words[i]))
                ans.push_back(words[i]);
        }
        return ans;
    }

};

int main(){

    vector<string> words{"a","aa","aaa","aaaa","aaaab"};
    Solution s;
    vector<string> ans = s.findAllConcatenatedWordsInADict(words);
    for(string a:ans){
        cout << a << endl;
    }

}

