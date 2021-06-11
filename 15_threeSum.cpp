//https://leetcode.com/problems/3sum/submissions/
#include <iostream>
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3){
            return ret;
        }
        set<vector<int>>ret_set;
        map<int,set<pair<int,int>>> twosum2ele;
        map<int,int>ele2pos;
        map<int,int>ele2cnt;
        map<int,bool>pos2exist;
        for(int i = 0; i < nums.size();i++){
            if (ele2cnt.find(nums[i]) == ele2cnt.end()){
                ele2cnt[nums[i]] = 0;
            }else if(ele2cnt[nums[i]] >= 3){
                pos2exist[i] = false;
                continue;
            }
            ele2pos[-1*nums[i]] = i;
            ele2cnt[nums[i]]+=1;
            pos2exist[i] = true;
        }
        for(int i = 0;i < nums.size();i ++){
            if(!pos2exist[i])
                continue;
            for(int j = i+1;j < nums.size();j ++){
                if(!pos2exist[j])
                    continue;
                if (ele2pos.find(nums[i]+nums[j]) != ele2pos.end() and ele2pos[nums[i]+nums[j]] > j){
                    vector<int> triple{nums[i],nums[j],-1*(nums[i]+nums[j])};
                    sort(triple.begin(),triple.end());
                    ret_set.insert(triple);
                }

            }
        }
        vector<vector<int>> vec_ret(ret_set.begin(),ret_set.end());
        return vec_ret;
    }
};
