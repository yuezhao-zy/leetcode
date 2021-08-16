#include "bits/stdc++.h"
#include "iostream"
using namespace std;

//https://leetcode-cn.com/problems/longest-consecutive-sequence/

void print_vec(vector<int> & vec){
    for(int i : vec)
        cout << i << " ";
    cout << endl;
}


typedef long long  ll;
const int max_n = 61;
ll comb[max_n][max_n];
ll mod = 1e9+7;

class Solution {
public:

    ll ini(int p){
        comb[1][1] = 1;

        for(int i = 2;i <= p; i ++){
            comb[i][1] = i;
            for(int j = 2;j < i;j ++){
                comb[i][j] = comb[i-1][j]+comb[i-1][j-1];
            }
            comb[i][i] = 1;
        }
        ll ret = 0;
        for(int i = 1;i < p;i ++){
            ret += i*((comb[p][i])/p) + i*( (comb[p][i])%p )/p;
            ret %= (mod-1);
        }
        return ret;
    }

    ll power(ll x,ll n,ll _mod=mod){

        ll ans = 1;
        ll multi = x;
        while (n){

            int record = n%10;
            ll base = 1;
            for(int i = 1;i <= 10;i ++){

                base *= multi;
                base %= _mod;
                if (i == record){
                    ans *= base;
                    ans %= _mod;

                    if (n/10 == 0)
                        break;

                }

            }
            multi = base;
            n/=10;


        }

        return ans;


    }



    int minNonZeroProduct(int p) {
//        ll times = ini(p); //NOTE 提供两种计算times的方式
        ll times = power(2,p-1,mod-1)-1;
        ll ans = power(2,p)-1;
        ll base = power(2,p)-2;
        ans %= mod;
        base %= mod;

        cout << ans << " " <<times << " ";
        ans *= power(base,times);
        ans %= mod;
        cout <<   power(base,times) << " " << pow(base,times) << endl;
        return ans;




    }
};
