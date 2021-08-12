#include "iostream"
#include "bits/stdc++.h"
//https://leetcode.com/problems/concatenated-words/
using namespace std;

map<int,vector<pair<int,int>>> out_edge;
map<int,vector<pair<int,int> >> in_edge;
const int MAX_N = 1010;
int pre[MAX_N];
int visit[MAX_N];
vector<int>ans;
class Solution {
public:

    vector<int> get_lastest_edge(int node){



    }

    void dfs(int u){
        for(int i = 0;i < out_edge[u].size();i ++){
            int v = out_edge[u][i].first;
            if(visit[v]){
                //发现环





            }

        }



    }




    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        fill(pre,pre+n+1,-1);
        fill(visit,pre+n+1,0);
        out_edge.clear();in_edge.clear();
        for(int i = 1;i <= edges.size();i ++){
            vector<pair<int,int>> vin,vout;
            in_edge[i] = vin;out_edge[i] = vout;
        }
        for(int i = 0;i < edges.size();i ++){
            vector<int>edge = edges[i];
            int start,end;start = edge[0];end = edge[1];
            pair<int,int> pout(end,i),pin(start,i);
            out_edge[start].push_back(pout);in_edge[end].push_back(pin);
        }
        for(int i = 1;i <= n;i ++){
            if (in_edge[i].size() > 1){
                return get_lastest_edge(i);
            }
        }
        //root在环上

        for(int i = 1;i <= n;i ++){
            if(!visit[i]){
                dfs(i);
                if(ans.size()==2){
                    return ans;
                }
            }

        }

    }
};