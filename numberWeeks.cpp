#include "iostream"
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {

        long long int sum=0;
        int _max=0;
        for(int i = 0;i < milestones.size();i ++){
            _max = max(_max,milestones[i]);
            sum+=milestones[i];
        }
        int remaining=sum-_max;
        if(_max-1 <= remaining ){
            return sum;
        } else
            return 2*remaining+1;

    }
};