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

const int max_n = 210;
ll dis[max_n];
ll path_cnt[max_n];
const int mod = 1e9+ 7;
ll weight[max_n][max_n];

class Solution {

public:

    void ini(int n,vector<vector<int>>& roads){
        for(int i = 0;i < n;i ++){
            path_cnt[i] = 0;
            dis[i] = LLONG_MAX;
            for(int j = 0;j < n;j ++){
                weight[i][j] = LLONG_MAX;
            }
            weight[i][i] = 0;
        }


        for(auto road:roads){
            weight[road[0]][road[1]] = road[2];
            weight[road[1]][road[0]] = road[2];

        }
    }

    int cmp(int u,int v){
        if( weight[u][v] == LLONG_MAX )
            return -1;
        else if(dis[u] + weight[u][v] < dis[v]){
            return 1;
        }else if(dis[u] + weight[u][v] == dis[v]){
            return 0;
        }else{
            return -1;
        }
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        ini(n,roads);
        dis[0] = 0;
        path_cnt[0] = 1;
        unordered_set<int> S;S.clear();

        while (S.find(n-1) == S.end()){
            int min_node = -1;
            ll min_dis = LLONG_MAX;
            
            for(int i = 0; i < n;i ++){
            
                if (dis[i] < min_dis and S.find(i) == S.end()){
                    min_dis = dis[i];
                    min_node = i;
                }
            }
            
            if (min_node != -1){
                S.insert(min_node);
                for(int i = 0;i < n;i ++){
                    if(S.find(i) == S.end()){
                        int cmp_ans = cmp(min_node,i);
                        
                        if (cmp_ans == 1){
                            dis[i] = dis[min_node] + weight[min_node][i];
                            
                            path_cnt[i] = path_cnt[min_node];
                        }else if(cmp_ans == 0){
                            path_cnt[i] += path_cnt[min_node];
                            path_cnt[i] %= mod;
                        }
                    }
                }
            }else{
                break;
            }
        }
        // cout << dis[n-1] x<< endl;
        return path_cnt[n-1];
    }
};