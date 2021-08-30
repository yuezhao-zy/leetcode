#include "vector"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//https://leetcode-cn.com/problems/find-the-kth-largest-integer-in-the-array/
void print_vec(vector<int>vec){
    for(int v:vec)
        cout << v << " ";
    cout << endl;
}

void print_set(unordered_set<int> s){
    cout << " --- " << endl;
    for(auto i:s){
        cout << i << " ";
    }
    cout << endl;
    cout << " --- " << endl;
}

const int max_n = 15;
bool valid[1 << max_n];
int dp[1 << max_n];

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {

        int n = tasks.size();
        for(int subset = 0;subset < 1<<n;subset ++){
            valid[subset] = false;


            int need_time = 0;
            for(int i = 0;i < n;i ++){
                if(subset & 1 << i)
                    need_time += tasks[i];
            }
            if(need_time <= sessionTime)
                valid[subset] = true;
        }

        dp[0] = 0;
        for(int mask = 1; mask < 1<< n; mask ++){
            dp[mask] = INT_MAX;

            for(int subset = mask;subset;subset = (subset-1)&mask){
                if(valid[subset])
                    dp[mask] = min(dp[mask],dp[mask ^ subset] + 1);
            }
        }

        return dp[(1<<n)-1];



    }
};


