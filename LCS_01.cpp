#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
class Solution {
public:
    int leastMinutes(int n) {
        return ceil(log2(n))+1;
    }
};