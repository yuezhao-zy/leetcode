#include "bits/stdc++.h"
#include "iostream"
using namespace std;


class Solution {
public:

    string remove_valid(string s){
        vector<int> arr(s.length());
        vector<bool> valid(s.length());

        arr[0] = 0;
        for(int i = 1;i < s.length();i ++){
            if(s[i] == ']'){
                if( s[i-1] == '['){
                    if(i>=2){
                        arr[i] = arr[i-2] + 2;
                    }else
                        arr[i] = 2;
                    valid[i]=true;
                    valid[i-1]=true;
                }else if(i-arr[i-1]-1 >=0 && s[i-arr[i-1]-1] == '['){
                    valid[i]=true;valid[i-arr[i-1]-1]=true;
                    if(i-arr[i-1]-2>0)
                        arr[i] = arr[i-1] +  arr[i-arr[i-1]-2]+2;
                    else
                        arr[i] = 2 + arr[i-1];
                }
                else
                    arr[i] = 0;
            }else{
                arr[i] = 0;
            }
        }

        string ret;
        for(int i = 0;i <arr.size();i ++){
            if (!valid[i]){
                ret += s[i];
            }
        }
        return ret;
    }

    int minSwaps(string s) {
        s = remove_valid(s);
        if(s.length()==0)
            return 0;
        return int((s.length()/2+1)/2);


    }
};
