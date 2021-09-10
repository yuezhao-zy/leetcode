#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

class Solution {
public:
    int halfQuestions(vector<int>& questions) {
        int n = questions.size()/2;
        int ans = 0;
        unordered_map<int,int> q_map;q_map.clear();
        for(int q:questions){
            if(q_map.find(q) == q_map.end())
                q_map[q] = 1;
            else
                q_map[q] ++;
        }
        vector<int>cnt;cnt.clear();
        for(pair<int,int> num2cnt:q_map){
            cnt.push_back(num2cnt.second);
        }
        sort(cnt.begin(),cnt.end());

        for(int i = cnt.size()-1;i >= 0;i --){
            ans ++;
            if(cnt[i] >= n)
                break;
            n -= cnt[i];
        }

        return ans;

    }
};