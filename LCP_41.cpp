#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

class Solution {
public:

    bool is_valid(int x,int y,int m,int n){
        return x >= 0 and x < m and y >= 0 and y < n;
    }

    int dfs(int x,int y,vector<string>& chessboard) {

        int x_move[] = {-1,1,0,0,-1,-1,1,1};
        int y_move[] = {0,0,-1,1,-1,1,-1,1};

        int ans = 0;
        vector<pair<int,int>> all_vec;all_vec.clear();
        int m = chessboard.size(),n = chessboard[0].size();
        for(int i = 0;i < 8;i ++){
            int _x = x+ x_move[i],_y = y + y_move[i];
            int white = 0;
            bool suc = false;
            vector<pair<int,int>> vec;vec.clear();
            while (is_valid(_x,_y,m,n)){
                if(chessboard[_x][_y] == 'X'){
                    ans += white;
                    suc = true;
                    break;
                }else if(chessboard[_x][_y] == '.'){
                    break;
                }else if(chessboard[_x][_y] == 'O'){
                    white ++;
                    vec.push_back(pair<int,int>{_x,_y});
                }
                _x = _x + x_move[i];
                _y = _y + y_move[i];
            }
            if(suc){
                for(pair<int,int> pos : vec){
                    chessboard[pos.first][pos.second] = 'X';
                    all_vec.push_back(pair<int,int>{pos.first,pos.second});
                }
            }
        }
        for(pair<int,int> pos : all_vec){
            ans += dfs(pos.first,pos.second,chessboard);
        }
        return ans;

    }



    int flipChess(vector<string>& chessboard) {
        int m = chessboard.size(),n = chessboard[0].size();
        int ans = 0;
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                if(chessboard[i][j] == '.'){
                    vector<string> _chessboard(chessboard);
                    _chessboard[i][j] = 'X';
                    ans = max(ans,dfs(i,j,_chessboard));
                }
            }
        }
        return ans;


    }
};