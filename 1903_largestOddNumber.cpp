#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;
        for(int i = num.length()-1;i >= 0;i --){
            int int_num = num[i]-'0';
            if(int_num % 2){
                return num.substr(0,i+1);
            }

        }
        string ans = "";
        return ans;
    }
};