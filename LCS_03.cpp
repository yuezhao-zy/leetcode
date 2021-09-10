#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int max_n = 510;
// const int max_n = 5;
int visited[max_n][max_n];
int area[max_n*max_n];

class Solution {
public:

    void ini(){
        for(int i = 0;i < max_n;i ++){
            for(int j = 0;j < max_n;j ++){
                visited[i][j] = -1;
            }
        }
        for(int i = 0;i < max_n*max_n;i ++){
            area[i] = 0;
        }
    }

    bool is_valid(int x,int y,vector<string>& grid){
        int m = grid.size(),n = grid[0].size();
        return x >= 0 and x < m and y >= 0 and y < n and grid[x][y] != '0';
    }


    void dfs(int x,int y,int index,vector<string>& grid){
        visited[x][y] = index;
        if(area[index] != -1)
            area[index] ++;
        int x_move[] = {-1,1,0,0};
        int y_move[] = {0,0,-1,1};
        for(int i = 0;i < 4;i ++){
            if(is_valid(x+x_move[i],y+y_move[i],grid)){
                if(visited[x+x_move[i]][y+y_move[i]] == -1 and grid[x+x_move[i]][y+y_move[i]] == grid[x][y]){
                    dfs(x+x_move[i],y+y_move[i],index,grid);
                }
            }else{
                area[index] = -1;
            }
        }

    }

    int largestArea(vector<string>& grid) {
        ini();
        int m = grid.size(),n = grid[0].size();
        int index = 0;
        int ans = 0;

        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                if(visited[i][j] == -1 and grid[i][j] != '0'){
                    dfs(i,j,index,grid);
                    ans = max(ans,area[index]);
                    index ++;
                }

            }
        }
        return ans;
    }
};

