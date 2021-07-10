#include <iostream>
#include "bits/stdc++.h"
using namespace  std;

//https://leetcode.com/problems/word-break-ii/submissions/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        bool can_reach[s.size()+1];
        vector<string> reachs[s.size()+1];
        for (int i = 0;i <= s.size();i ++){
            vector<string>emp_vec;emp_vec.clear();
            reachs[i] = emp_vec;
        }
        fill(can_reach,can_reach+s.size(),false);
        can_reach[0] = true;
        vector<string>start_vec;start_vec.clear();
        start_vec.push_back("");
        reachs[0] = start_vec;
        for(int i = 0;i < s.size();i ++){
            if (!can_reach[i])
                continue;
            for(int j = 0;j < wordDict.size();j ++){
                if (s.substr(i,wordDict[j].length()) == wordDict[j]){
                    can_reach[i+wordDict[j].length()] = true;
                    for(int _i  = 0;_i < reachs[i].size();_i++){
                        string tmp = reachs[i][_i];
                        if (tmp.size() == 0)
                            tmp += wordDict[j];
                        else
                            tmp += " "+wordDict[j];
                        reachs[i+wordDict[j].length()].push_back(tmp);
                    }
                }
            }
        }
        return reachs[s.size()];


    }
};


