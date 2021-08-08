#include "bits/stdc++.h"
#include "iostream"

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

        int sum=0;
        priority_queue<int> pq;
        for(int pile:piles){
            pq.push(pile);
            sum += pile;
        }
        for(int i = 0;i < k;i ++){
            int t = pq.top();
            pq.pop();
            sum -= int(t/2);
            pq.push(t-int(t/2));
        }
        return sum;
    }
};