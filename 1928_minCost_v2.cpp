#include "iostream"
#include "bits/stdc++.h"
using namespace std;

const int max_time = 1e3+2;
const int max_n = 1e3+2;

class Solution {
public:
    vector<pair<int,int>> g[1005];
    int f[1005][1005];
    int minCost(int T, vector<vector<int>>& edges, vector<int>& a) {
        int n=a.size();
        for(auto e:edges){
            int x=e[0],y=e[1],z=e[2];
            g[x].emplace_back(y,z);
            g[y].emplace_back(x,z);
        }
        memset(f,0x3f,sizeof f);
        f[0][0]=a[0];
        int ans=0x3f3f3f3f;
        for(int i=1;i<=T;i++) for(int x=0;x<n;x++) for(auto [y,w]:g[x]) if(i>=w) f[i][x]=min(f[i][x],f[i-w][y]+a[x]);
        for(int i=1;i<=T;i++) ans=min(ans,f[i][n-1]);
        return ans==0x3f3f3f3f?-1:ans;
    }
};

