#include <iostream>
#include "bits/stdc++.h"
using namespace  std;

//https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool can_reach[nums.size()];
        fill(can_reach,can_reach+nums.size(),false);
        can_reach[0] = true;
        for(int i = 0;i < nums.size();i ++){
            if (not can_reach[i]){
                continue;
            }
//            cout << i << endl;
            for(int j = 0;j <= nums[i] and i+j < nums.size();j ++){
                can_reach[i+j] = true;
//                cout << "can reach " << i+j << endl;
                if(i+j == nums.size()-1){
                    return true;
                }
            }
//            cout << endl;
        }
        return false;
    }
};

