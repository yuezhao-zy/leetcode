#include "bits/stdc++.h"
#include "iostream"
using namespace std;

// https://leetcode.com/contest/biweekly-contest-58/problems/minimum-total-space-wasted-with-k-resizing-operations/
const int max_n = 210;
int max_height_index[max_n][max_n];
int two_dim_num_box[max_n][max_n];
int one_dim_num_box[max_n];
int dp[max_n][max_n];

class Solution {
public:


    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0;

        one_dim_num_box[0] = nums[0];
        for(int i = 1;i < nums.size();i ++)
            one_dim_num_box[i] = one_dim_num_box[i-1]+nums[i];
        for(int i = 0;i < nums.size();i ++){
            max_height_index[i][i] = i;
            two_dim_num_box[i][i] = nums[i];
            for(int j = i+1;j < nums.size();j ++){
                two_dim_num_box[i][j] = one_dim_num_box[j]-one_dim_num_box[i]+nums[i];
                max_height_index[i][j] = max_height_index[i][j-1];
                int h = nums[j];
                if (h > nums[max_height_index[i][j-1]]){
                    max_height_index[i][j] = j;
                }
            }
        }

        for(int i = 0;i < nums.size();i ++){
            dp[i][1] = nums[max_height_index[0][i]]*(i+1)-two_dim_num_box[0][i];
            for(int j = 2;j <= min(k+1,i);j ++){
                dp[i][j] = INT_MAX;
                for(int m = 0;m < i;m ++){

                    dp[i][j] = min(dp[i][j],dp[m][j-1]+nums[max_height_index[m+1][i]] * (i-m)-two_dim_num_box[m+1][i]);
                }

            }
        }

        return dp[nums.size()-1][k+1];

    }
};
