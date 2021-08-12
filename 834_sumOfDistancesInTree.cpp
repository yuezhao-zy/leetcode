#include "bits/stdc++.h"
#include "iostream"
using namespace std;

const int max_n=3*1e4+1;
int dp[max_n];
int parents[max_n];

void print_vec(vector<int> & vec){
    for(int i : vec)
        cout << i << " ";
    cout << endl;
}

class Solution {
public:

    int dfs(int u,int parent, vector<vector<int>> &child,vector<int> &sub_node_cnt){
        // cout << parent << "->" << u << " has " << child[u].size() << " child" << endl;
        if (dp[u]!=-1)
            return dp[u];
        dp[u] = 0;

        if(child[u].size() == 1 and parent != -1){
            sub_node_cnt[u]=0;
            return dp[u];
        }//叶子节点

        for(int c:child[u]){
            if (c == parent){
                continue;
            }
            // cout << "child" << c << endl;
            parents[c] = u;
            dp[u] += dfs(c,u,child,sub_node_cnt)+sub_node_cnt[c]+1;
            sub_node_cnt[u] += 1+sub_node_cnt[c];
        }
        // cout << "dp[" << u << "]:" << dp[u] << endl;
        return dp[u];
    }

    int sum(int n,int i,vector<int> & sub_node_cnt,vector<int> & ans){
        if (ans[i] != -1)
            return ans[i];

        int _ = dp[i] + (n - sub_node_cnt[i] - 1);
        if (parents[i] != -1){
            // cout << i << "parent = " << parents[i] << " " << dp[parents[i]] << endl;
            _ += (sum(n,parents[i],sub_node_cnt,ans) - dp[i] - sub_node_cnt[i] - 1);
        }
        ans[i] = _;
        // cout << i << " " << ans[i] << endl;
        return ans[i];
    }



    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<int> sub_node_cnt(n);
        vector<vector<int>> child(n);
        vector<int> ans(n);

        for(vector<int>e:edges) {
            int start, end;
            start = e[0];
            end = e[1];
            child[start].push_back(end);
            child[end].push_back(start);
        }
        for(int i = 0; i < n;i ++){
            dp[i] = -1;
            ans[i] = -1;
            sub_node_cnt[i]=0;
        }
        parents[0] = -1;
        dfs(0,-1,child,sub_node_cnt);

        ans[0] = dp[0];
        for(int i = 0;i < n;i ++){
            sum(n,i,sub_node_cnt,ans);
        }
        return ans;

    }
};



int main(){
    int n;
    vector<vector<int>>edges;
    cin >> n;
    for(int i = 0;i < n-1;i ++){
        int start,end;
        cin >> start >> end;
        vector<int>_;
        _.push_back(start);_.push_back(end);
        edges.push_back(_);
    }

    Solution s;
    vector<int> ans = s.sumOfDistancesInTree(n,edges);
    print_vec(ans);







}