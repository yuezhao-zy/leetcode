#include "bits/stdc++.h"
#include "iostream"
using namespace std;

//https://leetcode-cn.com/problems/largest-rectangle-in-histogram/

void print_vec(vector<int> & vec){
    for(int i : vec)
        cout << i << " ";
    cout << endl;
}

typedef long long  ll;
const int max_n = 210;
int left_pos[max_n][max_n];
int right_pos[max_n][max_n];

class Solution {
public:

    bool cmp(int j,int i1,int i2){
        int r1 = right_pos[i1][j];
        int r2 = right_pos[i2][j];

        return  r1 <= r2;
    }

    int get_width(int i,int j){
        if (right_pos[i][j] == -1)
            return 0;
        return right_pos[i][j]-j+1;

    }

    void ini(vector<vector<char>>  matrix){
        for(int i = 0;i < matrix.size();i ++){
            int r = matrix[i].size()-1;
            for(int j = matrix[i].size()-1;j >= 0;j --){
                char symbol = matrix[i][j];
                if (symbol == '0'){
                    r = j-1;
                    right_pos[i][j] = -1;
                }else{
                    right_pos[i][j] = r;

                }
            }
        }
    }



    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;

        vector<char> bottom;bottom.clear();
        for (int j = 0; j < matrix[0].size(); ++j) {
            bottom.push_back('0');
        }

        matrix.insert(matrix.begin(),bottom);
        matrix.push_back(bottom);
        ini(matrix);
        int ans = 0;

        for(int j = 0;j < matrix[0].size();j ++){
            stack<int> s;
            while (!s.empty()) s.pop();
            s.push(0);
            for(int i = 1;i < matrix.size();i ++){
                while (!s.empty() and !cmp(j,s.top(),i)){
                    int top = s.top();s.pop();
                    int sidx = s.empty()?-1:s.top();
                    ans = max(ans,get_width(top,j) * (i-sidx-1));
                }
                s.push(i);
            }
        }

        return ans;

    }
};
