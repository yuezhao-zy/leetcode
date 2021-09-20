#include "iostream"
#include "bits/stdc++.h"
using namespace std;

const int max_time = 1e3+2;
const int max_n = 1e3+2;


vector<vector<int>>dp(max_time, vector<int>(max_n,INT_MAX));
vector<vector<int>>graph(max_n, vector<int>(max_n,INT_MAX));
vector<vector<int>>dir_graph(max_n, vector<int>(max_n,INT_MAX));
vector<int>visit_cnt(max_n, 0);
vector<vector<int>>in_node(max_n);
//vector<int>in_node(max_n, 0);

class Solution {
public:

    void dfs(int node,int maxTime,vector<int> & passingFees){
        // cout << "node:" << node << endl;
        int n = passingFees.size();
        for(int v:in_node[node]){
            if(visit_cnt[v] != in_node[v].size()){
                dfs(v,maxTime,passingFees);
            }
            int dis = dir_graph[v][node];
            for(int j = 0;j + dis <= maxTime;j ++){
                if(dp[j][v] != INT_MAX){
                    dp[j+dis][node] = min(dp[j+dis][node],dp[j][v]+passingFees[node]);
                }
            }
        }
    }

    void to_dirgraph(){
        queue<int>q;q.empty();
        q.push(0);
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (int i = 0; i < max_n; ++i) {
                if(graph[node][i] != INT_MAX and dir_graph[i][node] == INT_MAX){
                    dir_graph[node][i] = graph[node][i];
                    // cout << node << " -> " << i << endl;
                    in_node[i].push_back(node);
                    q.push(i);
                }
            }
        }

    }



    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {

        for(int i = 0;i < max_n;i ++){
            visit_cnt[i] = 0;
            in_node[i].clear();
            for(int j = 0;j < max_n;j ++){
                dp[i][j] = INT_MAX;
                graph[i][j] = INT_MAX;
                dir_graph[i][j] = INT_MAX;

            }
        }

        for(vector<int> e:edges){
            graph[e[0]][e[1]] = min(graph[e[0]][e[1]],e[2]);
            graph[e[1]][e[0]] = min(graph[e[1]][e[0]],e[2]);
        }
        to_dirgraph();
        int n = passingFees.size();

        dp[0][0] = passingFees[0];
        dfs(n-1,maxTime,passingFees);

        int ans = INT_MAX;

        for(int i = 0;i <= maxTime;i ++){
            ans = min(ans,dp[i][n-1]);
        }
        if(ans == INT_MAX)
            return -1;
        return ans;












    }
};

