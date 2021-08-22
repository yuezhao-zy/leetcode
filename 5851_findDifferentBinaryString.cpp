#include "vector"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//https://leetcode-cn.com/contest/weekly-contest-255/problems/find-unique-binary-string/
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

    string next_num(string num){
        int i = num.length()-1;
        bool jinwei = false;
        while (i >= 0){
            char c = num[i];
            if(jinwei){
                if(c == '0'){
                    num[i] = '1';
                    jinwei = false;
                    return num;
                }else{
                    num[i] = '0';
                }
            }else{

                if(c == '0'){
                    num[i] = '1';
                    jinwei = false;
                    return num;
                }else{
                    num[i] = '0';
                    jinwei = true;
                }
            }
            i --;
        }
        return num;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> nums_set;
        for(string num:nums)
            nums_set.insert(num);

        string num;
        num.push_back('0');
        int n = nums.size();
        for(int i = 0;i < n-1;i ++)
            num.push_back('0');

        while (nums_set.find(num) != nums_set.end()){
            cout << num;
            num = next_num(num);
            cout << " " << num << endl;
        }
        return num;

    }
};