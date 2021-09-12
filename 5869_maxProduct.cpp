#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int max_n = 12;
bool valid[1 << max_n];
int length[1 << max_n];


class Solution {
public:

    int maxProduct(string s) {
        int n = s.length();
        int const_ = (1 << n) -1;
        for(int mask = 1;mask < (1 << n);mask ++){
            length[mask] = 0;
            valid[mask] = true;
            for(int l = 0,r = n-1; l <= r;){

                while ((mask & (1 << l)) == 0 and l < r){
                    l ++;
                }
                while ((mask & (1 << r)) == 0 and l < r){
                    r --;
                }
                if((mask & (1 << l)) != 0 and (mask & (1 << r)) != 0){

                    if(s[l] != s[r]){
                        valid[mask] = false;
                        break;
                    }

                    if(l == r)
                        length[mask] ++;
                    else
                        length[mask] += 2;

                }else{
                    break;
                }


                l ++;
                r--;
            }

        }

        int ans = 0;
        for(int mask = 1;mask < (1 << n);mask ++){
            if(!valid[mask])
                continue;
            int non_mask = (~mask) & const_;
            for(int mask2 = non_mask; mask2 > mask;mask2 = (mask2-1) & (non_mask) ){
                if(!valid[mask2])
                    continue;
                ans = max(ans,length[mask] * length[mask2]);
            }
        }
        return ans;






    }
};

