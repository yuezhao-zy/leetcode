#include "vector"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

//https://leetcode-cn.com/submissions/detail/209864069/

void print_vec(vector<int>vec){
    for(int v:vec)
        cout << v << " ";
    cout << endl;
}

void print_set(unordered_set<int> s){
    cout << " --- " << endl;
    for(auto i:s){
        cout << i << " ";
    }
    cout << endl;
    cout << " --- " << endl;
}

const int max_n = 71;
const int mod = 1e9+7;
const int max_target = 810;
int dp[max_n][max_n*max_n];


class Solution {
public:

    void ini(vector<vector<int>>& mat){
        int m = mat.size(),n = mat[0].size();
        for(int i = 0;i < m;i ++){
            for(int k = 0;k < max_n*max_n;k ++){
                dp[i][k] = 0;
            }

        }
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int ans = INT_MAX;
        int m = mat.size(),n = mat[0].size();
        ini(mat);
        for(int j = 0;j < n;j ++){
            int num = mat[0][j];
            dp[0][num] = 1;
        }
        for(int i = 1;i < m;i ++){
            for(int j = 0;j < n;j ++){
                int num = mat[i][j];
                for(int k = 0;k < max_n*max_n;k ++){
                    if(dp[i-1][k])
                        dp[i][k+num] = 1;
                }
            }
        }
        for(int k = 0;k < max_n*max_n;k ++){
            if(dp[m-1][k]){
                ans = min(ans, abs(k-target));
            }
        }

        return ans;
    }
};