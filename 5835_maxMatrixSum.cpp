//https://leetcode-cn.com/problems/maximum-matrix-sum/

#include "vector"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void print_vec(vector<int>vec){
    for(int v:vec)
        cout << v << " ";
    cout << endl;
}
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg_cnt = 0;
        int zero_cnt = 0;
        int pos_cnt = 0;
        pair<int,int> min_abs_pos;
        int min_abs = INT_MAX;
        for(int i = 0;i < matrix.size();i ++){
            for(int j = 0;j < matrix.size();j ++){
                int num = matrix[i][j];
                if (num < 0) {
                    neg_cnt += 1;
                }else if(num == 0){
                    zero_cnt += 1;
                }
                if(abs(num) < min_abs){
                    min_abs = abs(num);
                    min_abs_pos.first = i;min_abs_pos.second = j;
                }
            }

        }
        ll sum = 0;

        for(int i = 0;i < matrix.size();i ++){
            for(int j = 0;j < matrix.size();j ++){
                int num = matrix[i][j];
                if (i == min_abs_pos.first and j == min_abs_pos.second)
                    continue;
                sum += abs(num);
            }
        }
        cout << sum << endl;
        cout << min_abs_pos.first << " " << min_abs_pos.second << endl;
        if(neg_cnt % 2 == 0 or zero_cnt >= 1){
            sum += abs(matrix[min_abs_pos.first][min_abs_pos.second]);
        }else{
            sum += -1*abs(matrix[min_abs_pos.first][min_abs_pos.second]);
        }



        return sum;

    }
};