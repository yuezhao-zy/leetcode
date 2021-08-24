#include "bits/stdc++.h"
#include "iostream"
using namespace std;

//https://leetcode-cn.com/problems/integer-replacement/

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
    int integerReplacement(int n) {
        queue<pair<int,int>>q;
        q.push(pair<int,int>(n,0));

        while (!q.empty()){
            pair<int,int> pair_front = q.front();
            int front = pair_front.first,times = pair_front.second;
            q.pop();
            if (front == 1)
                return times;
            if(front % 2)
                q.push(pair<int,int>(front/2,times+1));
            else{
                q.push(pair<int,int>(front+1,times+1));
                q.push(pair<int,int>(front-1,times+1));
            }

        }



    }
};