//https://leetcode.com/problems/permutation-sequence/
const int max_n = 10;
class Solution {
    public:

    int factorial[max_n];

    int cal_factorial(int n){
            if (factorial[n] != -1){
                        return factorial[n];
                    }else{
                                return n* cal_factorial(n-1);
                            }
        }
    string dfs(int k,vector<char> nums){
            if(k==0){
                        string ans = "";
                        for(int i = 0;i < nums.size();i ++){
                                        ans += nums[i];
                                    }
                        return ans;
                    }
            int first_index = k / cal_factorial(nums.size()-1);
            int remaining = k % cal_factorial(nums.size()-1);
            char first_num = nums[first_index];
            nums.erase(nums.begin()+first_index);
            return first_num + dfs(remaining,nums);
        }

    string getPermutation(int n, int k) {
            for(int i = 0;i < max_n;i ++){
                        factorial[i] = -1;
                    }
            factorial[1]=1;
            vector<char>nums;
            for(int i = 0;i < n;i ++){
                        nums.push_back('1'+i);
                    }
            return dfs(k-1,nums);

        }
};
