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
        string tmp = "";
        for(int i = 0;i < s.length();i ++){
            tmp += s[i];
            if(tmp.length() >= part.length() and  tmp.substr(tmp.length()-part.length()) == part){
                tmp = tmp.substr(0,tmp.length()-part.length());
            }
        }
        return tmp;

    }
};