#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX_N = 1e5+10;
int dp[MAX_N][3];
const int mod=1e9+7;
//https://leetcode.com/contest/weekly-contest-252/problems/count-number-of-special-subsequences/
class Solution {
public:


    int countSpecialSubsequences(vector<int>& nums) {

        for(int i = 0;i < nums.size();i ++){
            for(int j = 0;j < 3;j ++){
                dp[i][j]=0;
            }
        }
        if (nums[0]==0) { dp[0][0] = 1; }
        for(int i = 1;i < nums.size();i ++){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            if (nums[i] == 0)   dp[i][0] =(2*dp[i-1][0]+1)%mod;
            if (nums[i] == 1)   dp[i][1] = (dp[i-1][0]+(2*dp[i-1][1])%mod)%mod;
            if (nums[i] == 2)   dp[i][2] = (dp[i-1][1]+(2*dp[i-1][2])%mod)%mod;

        }
        return dp[nums.size()-1][2];

    }
};

