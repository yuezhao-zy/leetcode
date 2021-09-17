#include "iostream"
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<pair<char,int>> match_index;
        while (!match_index.empty())
            match_index.pop();
        int push_val;
        cout << part.length() << endl;
        for(int i = 0;i < s.length();i ++){
            int top;
            if(!match_index.empty())
                top = match_index.top().second;
            else
                top = 0;

            if(s[i] == part[top]){
                push_val = top+1;
            }else if(s[i] == part[0])
                push_val = 1;
            else
                push_val = 0;
//            int push_val = s[i] == part[top] ? top+1:0;
            cout  << s[i] << " "  << push_val << endl;

            match_index.push(pair<char,int>(s[i],push_val));
            // cout << s[i] << endl;
            // cout << match_index.size() << endl;
            if(push_val ==part.length()){
                cout << "pop " << i << endl;
                for(int _ = 0;_ < part.length();_++){
                    match_index.pop();
                }
                if(!match_index.empty())
                    cout << match_index.top().second << endl;
            }


        }

        string ans = "";
        while (!match_index.empty()){
            ans += match_index.top().first;
            match_index.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};