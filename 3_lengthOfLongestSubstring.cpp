#include "iostream"
#include "string"
using namespace  std;
#include "bits/stdc++.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.length() < 2){
            return s.length();
        }

        int start,end;
        map<char,int> vals;
        vals[s[0]] = 0;
        start = 0;end = 0;
        int res = -1;
        for(int i = 1;i < s.length();i ++){

            if(vals.find(s[i]) == vals.end() || vals[s[i]] < start){

            }else{
                start = vals[s[i]]+1;
            }
            vals[s[i]] = i;
            end ++;
            res = max(res,end-start+1);
//            cout << start <<" " << end << " " << res << endl;
        }

        return res;
    }
};

int main(){

    Solution s;
    cout << s.lengthOfLongestSubstring("ww");

}