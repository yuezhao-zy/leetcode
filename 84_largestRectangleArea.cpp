#include "vector"
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ans = 0;
        //维护非严格单调递增栈
        vector<int> ret(heights.size());


        if (heights.size() == 0) return 0;
        heights.push_back(0);
        s.push(0);

        for(int i = 1;i < heights.size();i ++){
            if (heights[i] >= heights[s.top()]){
                s.push(i);
            }

            else{
                //弹栈
                while (!s.empty() and heights[s.top()] > heights[i]){
                    int top = s.top();
                    s.pop();
                    ret[top] = heights[top]*(i-top);
                }
                s.push(i);
            }
        }


        while (!s.empty()) s.pop();

        heights.pop_back();
        heights.insert(heights.begin(),0);

        s.push(heights.size()-1);
        for(int i = heights.size()-2;i >= 0;i --){
            if (heights[i] >= heights[s.top()]){
                s.push(i);
            }
            else{
                //弹栈
                while (!s.empty() and heights[s.top()] > heights[i]){
                    int top = s.top();
                    s.pop();
                    ret[top-1] += heights[top]*(top-i-1);
                    ans = max(ans,ret[top-1]);
                }
                s.push(i);
            }
        }



        return ans;
    }
};