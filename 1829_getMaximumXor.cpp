#include "iostream"
#include "bits/stdc++.h"
using namespace std;

int bit_get(int mask,int index){
    return mask & ( 1 << index);
}

int bit_set(int mask,int index,int value){
    if(value)
        mask |= (1 << index);
    else
        mask &= ~(1 << index);
    return mask;
}

int mask_not(int mask,int maximumBit){
    int ret = 0;
    for(int i = maximumBit-1;i >= 0;i --){
        int not_value = bit_get(mask,i) == 0 ? 1 : 0;
        ret = (ret << 1) + not_value;
    }
    return ret;
}

int mask_sub(int mask,int num,int maximumBit){
    int ret = 0;
    for(int i = maximumBit-1;i >= 0;i --){
        int mask_i = bit_get(mask,i) == 0 ? 0 : 1,num_i = bit_get(num,i) == 0 ? 0 : 1;
        int value = mask_i != num_i;
        ret = (ret << 1) + value
                ;
    }
    return ret;

}

class Solution {
public:




    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mask = 0;
        for(int num:nums){
            for(int i = 0;i < maximumBit;i ++){
                int mask_i = bit_get(mask,i) == 0 ? 0 : 1,num_i = bit_get(num,i) == 0 ? 0 : 1;
                int value = mask_i != num_i;
                mask = bit_set(mask,i,value);
            }
        }
        vector<int> ret;ret.clear();
        ret.push_back(mask_not(mask,maximumBit));
        for(int i = nums.size()-1;i > 0;i --){
            mask = mask_sub(mask,nums[i],maximumBit);
            ret.push_back(mask_not(mask,maximumBit));
        }
        return ret;
    }
};