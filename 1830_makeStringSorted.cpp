#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int alphabet = 26;
const int max_n = 3010;
int cnt[alphabet];
int sum_cnt[alphabet];
ll factorial[max_n];
ll inverse_factorial[max_n];
const int mod = 1e9+7;

class Solution {
public:

    int pow_n(int x,int m){
        //x^m % mod base 2 复杂度 log m
        int cur_m = (m & 1) == 0 ? 0 : 1;
        ll ans = cur_m == 0 ? 1 : x;
        ll base = x;
        m = m >> 1;
        while (m){
            cur_m = (m & 1) == 0 ? 0 : 1;
            base = base * base;
            base %= mod;
            ans = cur_m == 0 ? ans : ans * base;
            ans %= mod;
            m = m >> 1;
        }
        return ans;
    }
    void get_factorial(){
        factorial[0] = 1;
        factorial[1] = 1;
        inverse_factorial[1] = pow_n(factorial[1],mod-2); //TODO 初始化
        for(int i = 2;i < max_n;i ++){
            factorial[i] = factorial[i-1] * i;
            factorial[i] %= mod;
            inverse_factorial[i] = pow_n(factorial[i],mod-2);
        }

    }

    int makeStringSorted(string s) {
        for(int i = 0;i < alphabet;i ++) { cnt[i] = 0;}
        for(char c:s) cnt[c-'a'] ++;
        get_factorial();
        ll ans = 0;
        ll numerator = 0;
        int n = s.length();
        for(int i = 0;i < n;i ++){
            ll cur_ans = 0;
            char c = s[i];
            ll Denominator = 1;
            for(int j = 0;j < alphabet;j ++){
                int count = cnt[j];
                if(count != 0){
                    if(j < c-'a')
                        numerator += count;
                    Denominator *= inverse_factorial[count];
                    Denominator %= mod;

                }
            }
            numerator  *= factorial[n - i - 1];
            numerator %= mod;

            cnt[c-'a'] -= 1;
            cur_ans = numerator * Denominator;
            cur_ans %= mod;

            ans += cur_ans;
            ans %= mod;
        }
        return ans;

    }
};
