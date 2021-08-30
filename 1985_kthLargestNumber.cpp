#include "vector"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//https://leetcode-cn.com/problems/find-the-kth-largest-integer-in-the-array/
void print_vec(vector<int>vec){
    for(int v:vec)
        cout << v << " ";
    cout << endl;
}

void print_set(unordered_set<int> s){
    cout << " --- " << endl;
    for(auto i:s){
        cout << i << " ";
    }
    cout << endl;
    cout << " --- " << endl;
}
bool cmp (const string & a,const string & b){
    if(a.length() < b.length())
        return true;
    if(a.length() > b.length())
        return false;

    return a < b;
}



class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        return nums[nums.size()-k];
    }
};
