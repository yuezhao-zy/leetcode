//https://leetcode.com/problems/trapping-rain-water/submissions/
class Solution {

public:
    int dfs(int s,int e,vector<int>& height){
        if (e == s+1){
            return 0;
        }
    int num_box = 0;

        if (height[s] > height[e]){
            for(int i = e-1;i > s;i --){
                if (height[i] > height[e]){
                    int right_water = height[e]*(e-i-1)-num_box;

                    return right_water+dfs(s,i,height);
                }
                num_box += height[i];
            }
        }
        else{
            for(int i = s+1;i < e;i ++){
                if (height[i] > height[s]){
                    int left_water = height[s]*(i-s-1)-num_box;

                    return left_water+dfs(i,e,height);
                }
                num_box += height[i];
            }
        }



        return min(height[s],height[e])*(e-s-1)-num_box;

    }

    int trap(vector<int>& height) {
        return dfs(0,height.size()-1,height);
    }
};
