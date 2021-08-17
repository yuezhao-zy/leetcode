#include "vector"
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int ret = 0;
        height.push_back(0);
        vector<int> index;
        for(int i = 0; i < height.size(); i++) {
            while(index.size() > 0 && height[index.back()] >= height[i]) {
                int h = height[index.back()];
                index.pop_back();
                int sidx = index.size() > 0 ? index.back() : -1; //直接记录的两个端点的宽度 index_back 表示左边最近的比top小的位置 i表示右边比top小的位置。 直接解决凹形结构。
                ret = max(ret, h * (i-sidx-1));
            }
            index.push_back(i);
        }
        return ret;
    }

};


