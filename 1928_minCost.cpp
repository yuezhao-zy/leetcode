class Solution {
private:
    // 极大值
    static constexpr int INFTY = INT_MAX / 2;

public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<int>> f(maxTime + 1, vector<int>(n, INFTY));
        f[0][0] = passingFees[0];
        for (int t = 1; t <= maxTime; ++t) {
            for (const auto& edge: edges) {
                int i = edge[0], j = edge[1], cost = edge[2];
                if (cost <= t) {
                    f[t][i] = min(f[t][i], f[t - cost][j] + passingFees[i]);
                    f[t][j] = min(f[t][j], f[t - cost][i] + passingFees[j]);
                }
            }
        }

        int ans = INFTY;
        for (int t = 1; t <= maxTime; ++t) {
            ans = min(ans, f[t][n - 1]);
        }
        return ans == INFTY ? -1 : ans;
    }
};
