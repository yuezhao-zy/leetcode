#include "bits/stdc++.h"
#include "iostream"
# include<ctime>
using namespace std;
typedef long long ll;
class Solution {
public:

    int not_mask(int mask,int pos){

        // cout << pos << " " << mask << endl;
        if(((1 << pos) & mask) == 0){
            mask = mask | (1 << pos);
        }else{
            mask = mask & ~(1 << pos);
        }
        return mask;
    }
    void bprint(int p){
        int i=0;
        int bit1 = 1;
        for (i=sizeof (p) * 8-1;i>=0; i--){
            unsigned int x = (((bit1<<i)&p) !=0);
            printf("%d", x);
        }

        printf("\n");
    }
    long long wonderfulSubstrings(string word) {
        int mask = 0;

        unordered_map<int,int> cnt;cnt.clear();
        cnt[0] = 1;
        ll ans = 0;

        for(int i = 0; i < word.length();i ++){
            // cout << "word:" << word[i] << endl;
            mask = not_mask(mask,(word[i]-'a'));

            for(int j = 0;j < 10;j ++){
                int mask_ = not_mask(mask,j);
                ans += cnt[mask_];
            }

            if(cnt.find(mask) == cnt.end())
                cnt[mask] = 0;
            ans += cnt[mask];
            cnt[mask] ++;
            // bprint(mask);
            // cout << "mask" << mask << " cnt:" << cnt[mask] << "ans:" << ans <<endl;
        }


        return ans;


    }
};


