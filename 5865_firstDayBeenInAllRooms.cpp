typedef long long ll;
const int max_n = 1e5+10;
ll cnt[max_n];
ll sum_cnt[max_n];
int mod = 1e9+7;
class Solution {
public:

    void ini(){
        for(int i = 0;i < max_n;i ++){
            cnt[i] = 0;
            sum_cnt[i] = 0;
        }
    }

    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        for(int i = 0;i < n-1;i ++){
            if(nextVisit[i] == i){
                cnt[i] = 2;
            }else{
                cnt[i] = 2 + sum_cnt[i-1]-sum_cnt[nextVisit[i]] + mod;
                cnt[i] %= mod;
                cnt[i] += cnt[nextVisit[i]];
                cnt[i] %= mod;
            }
            if (i > 0)
                sum_cnt[i] = sum_cnt[i-1]+cnt[i] ;
            else
                sum_cnt[i] = cnt[i];
            sum_cnt[i] %= mod;
        }
        return sum_cnt[n-2];
    }
};