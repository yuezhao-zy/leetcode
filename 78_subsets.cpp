#include "iostream"
#include "bits/stdc++.h"
using namespace std;

const int max_n = 10;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ret;ret.clear();
        int n = nums.size();
        for(int mask = 0;mask < (1 << n);mask ++){
            vector<int> cur_ret;cur_ret.clear();
            for(int i = 0;i < n;i ++){
                if(mask & (1 << i)){
                    cur_ret.push_back(nums[i]);
                }
            }
            ret.push_back(cur_ret);
        }
        return ret;
    }
};