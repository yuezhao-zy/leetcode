#include "bits/stdc++.h"
#include "iostream"
using namespace std;


void print_vec(vector<int> & vec){
    for(int i : vec)
        cout << i << " ";
    cout << endl;
}


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0)
            return;
        int last_num = nums[nums.size()-1];
        for(int i = nums.size()-2;i >= 0;i --){
            int first_num = nums[i];
            if(first_num < last_num){
                //转置
                int min_bigger_index = -1,min_bigger_nb = INT_MAX;
                for(int j = nums.size()-1,cnt = 0; cnt < (nums.size()-i)/2 ;j --,cnt++){
                    int swap_pos = nums.size()+i-j;
                    if (nums[j] > first_num){
                        if (nums[j] < min_bigger_nb){
                            min_bigger_nb = nums[j];
                            min_bigger_index = swap_pos;
                        }else if(nums[j] == min_bigger_nb and swap_pos < min_bigger_index){
                            min_bigger_nb = nums[j];
                            min_bigger_index = swap_pos;
                        }
                    }

                    if(nums[swap_pos] > first_num){
                        if(nums[swap_pos] < min_bigger_nb){
                            min_bigger_nb = nums[swap_pos];
                            min_bigger_index = j;
                        }else if(nums[swap_pos] == min_bigger_nb and j < min_bigger_index){
                            min_bigger_nb = nums[j];
                            min_bigger_index = j;
                        }
                    }


                    int tmp = nums[j];
                    nums[j] =  nums[swap_pos];
                    nums[swap_pos] = tmp;
                }
                if(min_bigger_index != -1){
                    nums[i] = nums[min_bigger_index];
                    nums[min_bigger_index] = first_num;
                    return;
                }
            }
            last_num = nums[i];
        }

        for(int i = 0;i < nums.size()/2;i ++){
            int tmp = nums[i], swap_pos = nums.size()-i-1;
            nums[i] =  nums[swap_pos];
            nums[swap_pos] = tmp;
        }






    }
};

