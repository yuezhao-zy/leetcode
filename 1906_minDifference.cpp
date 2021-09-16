#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const int max_n = 1e5+10;
const int max_num = 101;
vector<vector<int>>sum_cnt (max_n, vector<int>(max_num,0));

class Solution {
public:

    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {

        sum_cnt[0][nums[0]] = 1;
        for(int i = 1; i < nums.size();i ++){
            copy_n(sum_cnt[i-1].begin(), max_num, sum_cnt[i].begin());
            sum_cnt[i][nums[i]] ++;
        }
        vector<int> ret;ret.clear();
        for(int i = 0;i < queries.size();i ++){
            int start = queries[i][0],end = queries[i][1];
            int last_num = -1;
            int min_offset = INT_MAX;
            for(int j = 0;j < max_num;j ++){
                int cnt = sum_cnt[end][j] - sum_cnt[start][j];
                cnt = nums[start] == j ? cnt + 1:cnt;
                if(cnt > 0){
                    if(last_num != -1){
                        min_offset = min(min_offset,j-last_num);
                    }
                    last_num = j;
                }
            }
            min_offset = min_offset == INT_MAX ? -1 : min_offset;
            ret.push_back(min_offset);
        }
        return ret;

    }
};
