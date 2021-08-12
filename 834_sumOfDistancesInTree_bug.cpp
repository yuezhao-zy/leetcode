#include "bits/stdc++.h"
#include "iostream"

using namespace std;
const int max_n=3*1e4+1;
int dp[max_n][max_n];

void print_vec(vector<int>  &vec){
    for(int i:vec)
        cout << i << " " ;
    cout << endl;
}

class Solution {
public:


    void dfs(int u,int parent,vector<vector<int>>& child,vector<vector<int>> &child_tree){
        for(int c:child[u]){
            if (c == parent){
                continue;
            }
            dp[u][c]=1;
            dp[c][u]=1;
            cout << parent << " -> " <<  u << " -> " << c << endl;
            child_tree[u].push_back(c);
            if (child[c].size()==1){
                //c为叶子节点
                dp[u][c] = 1;
                dp[c][u] = 1;
                cout << u << " " << c << "=1" << endl;
            }else{
                dfs(c,u,child,child_tree);

                for(int cc:child_tree[c]){
                    cout << cc << "is child tree of" << c << endl;
                    child_tree[u].push_back(cc);
                    dp[u][cc] = 1+dp[c][cc];
                    dp[cc][u] = 1+dp[c][cc];
                    cout << u << " " << cc << " = " << dp[u][cc] << endl;
                }
            }
        }
        cout << "u=" << u << endl;
        for(int c1:child[u]){
            for(int c2:child[u]){
                if(c1 == parent or c2 == parent or c1==c2)
                    continue;
                dp[c1][c2] = 2;
                dp[c2][c1] = 2;

                for(int c1cc:child_tree[c1]){
                    dp[c2][c1cc] = dp[c1][c1cc]+2;
                    dp[c1cc][c2] = dp[c1][c1cc]+2;

                    for(int c2cc:child_tree[c2]){
                        dp[c1cc][c2cc] = 2+dp[c1][c1cc]+dp[c2][c2cc];
                        dp[c2cc][c1cc] = 2+dp[c1][c1cc]+dp[c2][c2cc];



                    }
                }
                for(int c2cc:child_tree[c2]) {
                    dp[c1][c2cc] = dp[c2][c2cc]+2;
                    dp[c2cc][c1] = dp[c2][c2cc]+2;
                }
        }


    }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> child(n);
        vector<vector<int>> child_tree(n);
        for(vector<int>e:edges) {
            int start, end;
            start = e[0];
            end = e[1];
            child[start].push_back(end);
            child[end].push_back(start);
        }
        for(int i = 0; i < n;i ++){
            for(int j = 0;j < n;j ++)
                if (i == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = INT_MAX;
        }
        dfs(0,-1,child,child_tree);
        vector<int>ans;
        for(int i = 0;i < n;i ++){
            int _ = 0;
            for(int j = 0;j < n;j ++){
                cout << "dp" << i << " " << j << "=" << dp[i][j] << " ";
                _ += dp[i][j];
            }
            cout << endl;

            ans.push_back(_);
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
    //0 3 2 1
}