#include "bits/stdc++.h"
#include "iostream"
using namespace std;

//https://leetcode-cn.com/problems/number-of-ways-to-separate-numbers/

void print_vec(vector<int> & vec){
    for(int i : vec)
        cout << i << " ";
    cout << endl;
}

void print_str(int i,int j,string num){
    cout << "-------------";
    for(int k = i;k <= j;k ++){
        cout << num[k] << " ";
    }
    cout << endl;
}

typedef long long  ll;
#include "vector"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
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

const int max_n = 3510;
const int mod = 1e9+7;

int dp[max_n][max_n];

class Solution {
public:

    ll cmp(int l1,int r1,int l2,int r2,string num){
        int last_num_length = r1-l1+1, cur_num_length = r2-l2+1;
        if(last_num_length < cur_num_length)
            return true;
        else if(last_num_length > cur_num_length)
            return false;
        else{
            for(int i = 0;i < last_num_length;i ++){
                int last_num_index = l1+i,cur_num_index = l2+i;
                if(num[last_num_index] < num[cur_num_index])
                    return true;
                else if(num[last_num_index] > num[cur_num_index])
                    return false;
            }
        }
        return true;
    }

    int dfs(int i,int j,string num){
        //记录开始单词是num[i,j]的合法字符串
        if(dp[i][j] != -1)
            return dp[i][j];
        print_str(i,j,num);
        ll ans = 0;
        if (j == num.length()-1)
            return 1;
        if (num[j+1] == '0')
            return ans;
        for(int k = j+1;k < num.length();k ++){
            if (cmp(i,j,j+1,k,num)){
                ans += dfs(j+1,k,num);
                ans %= mod;
            }
        }
        dp[i][j] = ans;
        return ans;
    }

    void ini(){
        for(int i = 0;i < max_n;i ++){
            for(int j = 0;j < max_n;j ++)
                dp[i][j] = -1;
        }

    }


    int numberOfCombinations(string num) {
        ini();
        ll ans = 0;
        if(num[0] == '0')
            return 0;
        for(int j = 0;j < num.length();j ++){
            ans += dfs(0,j,num);
            ans %= mod;
        }
        return ans;
    }
};