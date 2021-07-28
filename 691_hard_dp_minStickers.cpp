#include "iostream"
#include "bits/stdc++.h"

using namespace std;
//https://leetcode.com/problems/stickers-to-spell-word/

map<string,int> dp;

class Solution {
public:

    map<char,int> to_counter(string target){
        map<char,int> counter;counter.clear();
        for(auto t : target){
            if (counter.find(t) == counter.end()){
                counter[t] = 1;
            }else{
                counter[t] += 1;
            }
        }
        return counter;
    }
    string sub_counter(map<char,int> &target,map<char,int> &wd){
        string new_target = "";
        for(map<char,int>::iterator iter = target.begin();iter!=target.end();iter++){
            char key=iter->first;int num = iter->second;
            if (wd.find(key) != wd.end()){
                num -= wd[key];
            }
            if (num > 0){
                for(int _ = 0; _ < num; _++)
                    new_target += key;
            }
        }
        return new_target;
    }

    int dfs(string target,vector<map<char,int>> & freq){

        if (dp.find(target) == dp.end()){
            if (target.length() == 0)
                return 0;
            int ans = INT_MAX;
            map<char,int>target_counter;target_counter.clear();target_counter = to_counter(target);
            for(map<char,int> wd : freq ){
                if ( wd.find( target[0]) != wd.end() ){
                    int sub_ans = dfs(sub_counter(target_counter,wd),freq);
                    ans = sub_ans != INT_MAX ? min(1+sub_ans,ans) : ans;
                }
            }
            dp[target] = ans;
        }

//        cout << target <<" " << dp[target] << endl;
        return dp[target];

    }


    int minStickers(vector<string>& stickers, string target) {
        dp.clear();
        vector<map<char,int>> freq;freq.clear();
        for (int i = 0; i < stickers.size(); ++i) {
            freq.push_back(to_counter(stickers[i]));
        }

        int ans =  dfs(target,freq);
        return  ans == INT_MAX ? -1 :ans;
    }
};
