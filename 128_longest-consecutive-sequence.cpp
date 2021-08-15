#include "bits/stdc++.h"
#include "iostream"
using namespace std;

//https://leetcode-cn.com/problems/longest-consecutive-sequence/

void print_vec(vector<int> & vec){
    for(int i : vec)
        cout << i << " ";
    cout << endl;
}

typedef long long  ll;
const int max_n = 61;
int comb[max_n][max_n];
ll mod = 1e9+7;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums;
        for(int i = 1;i < nums.size()-1;i ++){
            int left = nums[i-1],right = nums[i+1],mid = nums[i];
            if(left + right == 2*mid){
                if(i-1 > 0){

                }

                nums[i] = left;
                nums[i-1] = mid;

            }
        }
        return nums;
    }
};

int main(){

    vector<int> nums{0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    Solution s;
    vector<int> ans = s.rearrangeArray(nums);
    print_vec(ans);



}