#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const int max_n = 510;

vector<vector<int>> index_1(max_n, vector<int>(max_n));
vector<vector<int>> index_2(max_n, vector<int>(max_n));
vector<vector<bool>> visit_1(max_n, vector<bool>(max_n));
vector<vector<bool>> visit_2(max_n, vector<bool>(max_n));
vector<int> index_2_to_1(max_n*max_n);
vector<bool>  is_child(max_n*max_n);

class Solution {
public:

    void print_vec(vector<vector<int>>&vec,int m,int n){

        cout << "-------------" << endl;
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-------------" << endl;
    }


    void ini(){


        for(int i = 0;i < max_n;i ++){
            for(int j = 0;j < max_n;j ++){
                index_1[i][j] = -1;
                index_2[i][j] = -1;
                visit_1[i][j] = false;
                visit_2[i][j] = false;
            }
        }
        for(int i = 0;i < max_n*max_n;i ++){
            index_2_to_1[i] = -1;
            is_child[i] = true;
        }

    }

    bool is_valid(int x,int y,vector<vector<int>>& grid){
        int m = grid.size(),n = grid[0].size();
        return x >= 0 and x < m and y >= 0 and y < n  and grid[x][y] == 1;
    }

    void dfs(int x,int y,int index,vector<vector<int>>& grid,vector<vector<int>>& indexs, vector<vector<bool>> & visited,int island = 0){
        int x_move [] = {0,0,-1,1};
        int y_move [] = {-1,1,0,0};
        for(int i = 0;i < 4;i ++){
            int _x = x+x_move[i],_y = y+y_move[i];

            if(is_valid(_x,_y,grid) and !visited[_x][_y]){
                // cout << x << "->" << _x << " " << y << "->"  << _y << endl;
                visited[_x][_y] = true;
                indexs[_x][_y] = index;
                if(island == 1){
                    if(index_1[_x][_y] != index_2_to_1[index] or index_1[_x][_y] == -1){
                        is_child[index] = false;
                    }
                }
                dfs(_x,_y,index,grid,indexs,visited,island);
            }
        }





    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        ini();
        int m = grid1.size(), n = grid1[0].size();
        int index = 0;
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                if(!visit_1[i][j] and grid1[i][j]){
                    visit_1[i][j] = true;
                    index_1[i][j] = index;
                    dfs(i,j,index,grid1,index_1,visit_1);
                    index ++;
                }
            }
        }
        // print_vec(grid1,m,n);
        // print_vec(index_1,m,n);
        // cout << "index:" << index << endl;
        index = 0;
        int ans = 0;
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                if(!visit_2[i][j]  and grid2[i][j]){
                    // cout << i << " " << j << endl;
                    visit_2[i][j] = true;
                    index_2[i][j] = index;
                    index_2_to_1[index] = index_1[i][j];
                    if(index_2_to_1[index] == -1)
                        is_child[index] = false;
                    dfs(i,j,index,grid2,index_2,visit_2,1);

                    if(is_child[index]){
                        // cout << "index:" << index << "parent:" << index_2_to_1[index] << endl;
                        ans ++;
                    }
                    index ++;
                }
            }
        }
        // cout << "index:" << index << endl;
        // print_vec(grid2,m,n);
        // print_vec(index_2,m,n);

        return ans;

    }
};