#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int max_n = 1e5+1;
vector<vector<ll>> dp(max_n, vector<ll>(2,0));
vector<vector<int>> index_dp(max_n, vector<int>(2,-1));

class Solution {
public:

    long long maxAlternatingSum(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        dp[0][1] = nums[0];
        index_dp[0][1] = 0;
        dp[1][1] = max(nums[0],nums[1]);
        index_dp[1][1] = nums[0] > nums[1] ? 0 : 1;
        dp[1][0] = nums[0]-nums[1];
        index_dp[1][0] = 1;
        ll tmp;
        for(int i = 2;i < nums.size();i ++){

            copy_n(dp[i-1].begin(),2,dp[i].begin());
            copy_n(index_dp[i-1].begin(),2,index_dp[i].begin());
            tmp = max(dp[i-1][0]-nums[index_dp[i-1][0]]-nums[i],dp[i-1][1]-nums[i]);

            index_dp[i][0] = tmp > dp[i][0] ? i : index_dp[i][0];
            dp[i][0] = max(dp[i][0],tmp);
            tmp = max(dp[i-1][1]-nums[index_dp[i-1][1]]+nums[i],dp[i-1][0]+nums[i]);

            index_dp[i][1] = tmp > dp[i][1] ? i : index_dp[i][1];
            dp[i][1] = max(dp[i][1], tmp);

        }
        return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
    }
};