#include <iostream>
#include "bits/stdc++.h"
using namespace  std;

//https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1){
            return nums[0];
        }
        long long ans[2][nums.size()][2]; //ans[k][i][0]表示第i位未被选择的当前最大值 ans[k][i][1]表示第i位被选择的当前最大值 k=0表示第0位被选择 k=1表示第0位未被选择
        for(int i = 0;i < 2;i ++){
            for(int j = 0;j < nums.size();j ++){
                for(int k = 0;k < 2;k ++){
                    ans[i][j][k]=0;
                }
            }
        }
        ans[1][0][1]=nums[0];
        for(int i = 1;i < nums.size()-1;i ++){
            ans[0][i][0] = max(ans[0][i-1][0],ans[0][i-1][1]);
            ans[1][i][0] = max(ans[1][i-1][0],ans[1][i-1][1]);
            ans[0][i][1] = ans[0][i-1][0]+nums[i];
            ans[1][i][1] = ans[1][i-1][0]+nums[i];
            cout << i << ": " << ans[0][i][0] << " " << ans[1][i][0] << " " << ans[0][i][1] << " " << ans[1][i][1] << endl;
        }

        ans[0][nums.size()-1][0] = max(ans[0][nums.size()-1-1][0],ans[0][nums.size()-1-1][1]);
        ans[0][nums.size()-1][1] = ans[0][nums.size()-1-1][0]+nums[nums.size()-1];
        ans[1][nums.size()-1][0] = max(ans[1][nums.size()-1-1][0],ans[1][nums.size()-1-1][1]);

        int final_ans = max(max(ans[0][nums.size()-1][0],ans[0][nums.size()-1][1]),ans[1][nums.size()-1][0]);
        return final_ans;
    }
};


