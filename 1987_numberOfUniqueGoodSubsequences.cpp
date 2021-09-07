#include "vector"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//https://leetcode-cn.com/problems/number-of-unique-good-subsequences/
/*
 * 1. 初始化问题
 * 2. lastpos 记得更新
 * 3. 涉及mod的前缀和 记得作差的时候加上mod
 */
const int max_n = 1e5+10;
ll mod = 1e9+7;
ll sum_cnt[max_n];
ll cnt[max_n];
ll real_cnt[max_n];
ll real_sum_cnt[max_n];
class Solution {
public:

    void ini(){
        for(int i = 0;i < max_n;i ++){
            sum_cnt[i] = 0;
            cnt[i] = 0;
            real_cnt[i] = 0;
            real_sum_cnt[i] = 0;
        }
    }

    int numberOfUniqueGoodSubsequences(string binary) {
        ini();
        int n = binary.length();
        int last_pos[] = {-1,-1};
        if(binary[n-1] == 0){
            real_cnt[n-1] = 0;
            real_sum_cnt[n-1] = 0;
        }else{
            real_cnt[n-1] = 1;
            real_sum_cnt[n-1] = 1;
        }

        cnt[n-1] = 1;
        sum_cnt[n-1] = 1;
        last_pos[binary[n-1]-'0'] = n-1;
        for(int i = n-2;i >= 0;i --){
            int num = binary[i]-'0';
            if(last_pos[num] != -1){
                int last_num_pos = last_pos[num];
                cnt[i] = sum_cnt[i+1] - sum_cnt[last_num_pos] + mod;
                cnt[i] %= mod;
                cnt[i] += cnt[last_num_pos];
                cnt[i] %= mod;
                if(num == 0){
                    real_cnt[i] = 0;
                }else{
                    real_cnt[i] = cnt[i];
                }
            }else{
                cnt[i] = sum_cnt[i+1]+1;
                if(num == 0){
                    real_cnt[i] = 1;
                }else{
                    real_cnt[i] = cnt[i];
                }
            }
            sum_cnt[i] = sum_cnt[i+1] + cnt[i];
            real_sum_cnt[i] = real_sum_cnt[i+1] + real_cnt[i];
            last_pos[num] = i;
            cnt[i] %= mod;
            sum_cnt[i] %= mod;
            real_cnt[i] %= mod;
            real_sum_cnt[i] %= mod;
            // cout << cnt[i] << " " << sum_cnt[i] << " " << real_cnt[i] << " " << real_sum_cnt[i] << endl;
        }

        return real_sum_cnt[0];
    }
};