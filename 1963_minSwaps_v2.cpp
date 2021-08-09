#include "bits/stdc++.h"
#include "iostream"
using namespace std;

class Solution {
public:

    int minSwaps(string s) {
        int lb=0;
        int cnt=0;
        for(char c:s){
            if (c == '['){
                lb +=1;
            }else{
                if (lb > 0){
                    lb -=1;
                    cnt += 2;
                }
            }
        }
        int valid_len = (s.length()-cnt)/2;
        return int((valid_len+1)/2);
    }
};
