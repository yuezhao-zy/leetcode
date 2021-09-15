#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

const int max_n = 1e5+10;

class Solution {
public:

    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<std::pair<int,int>, int> myMap;
        for(vector<int> rec:rectangles){
            int rec_gcd = std::gcd(rec[0],rec[1]);
            int w = rec[0] / rec_gcd, h = rec[1] / rec_gcd;
            if(myMap.find(pair<int,int>{w,h}) == myMap.end()){
                myMap[pair<int,int>{w,h}] = 1;
            }else
                myMap[pair<int,int>{w,h}] ++;
        }
        ll ans = 0;
        for(pair<pair<int,int>,int> wh2cnt: myMap){
            ll cnt = wh2cnt.second;
            if(cnt > 1){
                ll cur = 0;
                if(cnt % 2 == 0){
                    cur = (cnt / 2) * (cnt-1);
                }else{
                    cur = (cnt-1) / 2 * cnt;
                }


                ans += cur;
            }
        }

        return ans;

    }
};