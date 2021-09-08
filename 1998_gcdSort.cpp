#include "vector"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//https://leetcode-cn.com/problems/gcd-sort-of-an-array
/*
 * 1. 初始化问题
 * 2. lastpos 记得更新
 * 3. 涉及mod的前缀和 记得作差的时候加上mod
 */

const int max_n = 3e5+10;
int root[max_n];
class Solution {
public:
    void ini(){
        for(int i = 0;i < max_n;i ++)
            root[i] = i;

    }

    int find(int x){
        return root[x] == x ? root[x] : (root[x] = find(root[x]));
    }
    void merge(int x,int y){
        int rx = find(x),ry = find(y);
        if(rx != ry){
            root[rx] = ry;
        }
    }

    unordered_set<int> get_factor(int x){
        unordered_set<int> ret;ret.clear();
        for(int i = 2;i <= x/i;i ++){
            while (x % i == 0){
                ret.insert(i);
                x /= i;
            }
        }
        if(x != 1)
            ret.insert(x);
        return ret;
    }

    bool gcdSort(vector<int>& nums) {
        ini();
        vector<int> old_nums;old_nums.clear();
        for(int num:nums){
            old_nums.push_back(num);
            unordered_set<int> factors = get_factor(num);
            for(int f : factors){ //利用质因子做中介
                if(f != num)
                    merge(f,num);
            }
        }

        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i ++){
            int new_num = nums[i],old_num = old_nums[i];
            if(new_num != old_num and find(new_num) != find(old_num))
                return false;
        }
        return true;

    }
};

