//https://leetcode-cn.com/problems/the-number-of-good-subsets/submissions/
typedef long long ll;
const int max_p = 10;
const int max_n = 31;
int valid[max_n];
ll dp[1 << max_p];
ll p_factor[1 << max_p];
ll cnt[max_n];
const int mod = 1e9+7;

class Solution {

public:

    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int>prime {2,3,5,7,11,13,17,19,23,29};
        int np = prime.size();
        for(int i = 0;i < max_n;i ++) {cnt[i] = 0;}
        for(int i = 0;i < (1<< max_p);i ++){dp[i] = 0;p_factor[i] = 0;}
        ll c = 1;
        for(int num:nums) cnt[num] ++;
        for(int i = 0;i < cnt[1];i ++){
            c *= 2;
            c %= mod;
        }
        for(int i = 2;i < max_n;i ++){
            valid[i] = false;
            p_factor[i] = 0;
            int num = i;
            int p_cnt = 0;
            bool flag = true;
            for(int p_index = 0;p_index < np;p_index ++){
                int p = prime[p_index];
                p_cnt = 0;
                while (num % p == 0){
                    num /= p;
                    p_factor[i] |= 1 << p_index;
                    p_cnt ++;
                    if(p_cnt > 1){
                        flag = false;
                        // cout << p << " " << flag << endl;
                        break;
                    }
                }
                if(!flag)
                    break;
            }

            valid[i] = flag;
        }
        dp[0] = 1;

        for(int i = 2;i < max_n; i++){
            if(!valid[i])
                continue;
            for(int mask = (1 << max_p) - 1;mask >= 0;mask --){
                if( mask & p_factor[i] ) continue;
                dp[mask | p_factor[i]] = (dp[mask | p_factor[i]] + (dp[mask] * cnt[i])) % mod;
            }
        }
        ll ans = 0;
        for(int mask = 1;mask < (1 << max_p);mask ++){
            ans += dp[mask];
            ans %= mod;
        }
        ans *= c;
        ans %= mod;
        return ans;
    }
};