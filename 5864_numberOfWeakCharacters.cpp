#include "vector"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//https://leetcode-cn.com/problems/the-number-of-weak-characters-in-the-game/

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& ps) {
        sort(ps.begin(), ps.end(), cmp);
        stack<vector<int>> st;
        int res = 0;
        for (int i = ps.size() - 1; i >= 0; --i) {
            while (!st.empty() && st.top()[1] <= ps[i][1]) {
                st.pop();
            }
            if (!st.empty()) {
                ++res;
            }

            st.push(ps[i]);
        }
        return res;
    }

    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    }
};
