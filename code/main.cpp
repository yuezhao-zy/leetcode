#include "bits/stdc++.h"
#include "iostream"

using namespace std;


class Solution {
public:

    int dfs(int s_pos,int lb,string s){
        int min_ = INT_MAX;
//        cout << "s:" << s_pos << " lb:" <<lb << " " <<s << endl;
        for(int i = s_pos;i < s.length();i ++){
            char c = s[i];
            if (c == '[' ){
                lb += 1;
            }else{
                if (lb > 0) lb -= 1;
                else{
                    //替换 ]
                    bool find = false;
                    for(int j = i + 1;j < s.length();j ++){
                        if (s[j] == '['){
                            s[j] = ']';
                            s[i] = '[';
//                            cout << i << " " << j << " " << s <<endl;
                            find = true;
                            int sub = dfs(i+1,lb+1,s);
                            if (sub != INT_MAX){
                                min_ = min(min_,sub+1);
                            }
                            s[j] = '[';
                        }
                    }
                    if (!find){
                        return INT_MAX;
                    }
                    else
                        return min_;

                }
            }
        }
//        cout <<s << endl;
        return 0;

    }

    string remove_valid(string s){
        vector<int> vec(s.length());
        vector<bool> valid(s.length());

        for (int i = 0;i < s.length();i ++){
            valid[i] = false;
            if (s[i] == '['){
                vec[i]= 0;
            }else if(s[i] == ']'){
                if(i > 0){
                    if(s[i-1] == '['){
                        vec[i] = 2;
                        valid[i-1]= true;valid[i]=true;
//                        cout << "?1 " << i-1 <<" " << i << s.substr(i-1,2) << endl;
                        if(i>1 and vec[i-2] == ']'){
                            vec[i] += vec[i-2];
//                            cout << "?2 " << i-2-vec[i-2]-1 << " " << i << s.substr(i-2-vec[i-2]-1,i-(i-2-vec[i-2]-1)+1) << endl;

                        }


                    }else{
                        if (i-vec[i-1]-1 >= 0 and  s[i-vec[i-1]-1] == '['){
                            vec[i] = 2+vec[i-1];
                            valid[i] = true;
                            valid[i-vec[i-1]-1] = true;
                            if (i-vec[i-1]-2>0)
                                 vec[i] += vec[i-vec[i-1]-2];
//                            cout << "?3 " << i-2-vec[i-2]-1 << " " << i  << s.substr(i-vec[i-1]-1,i-(i-vec[i-1]-1)+1) << endl;
                        }else{
                            vec[i] = 0;
                        }
                    }
                }else{
                    vec[i]= 0;
                }
            }

        }
        string ret;
        for(int i = 0;i <vec.size();i ++){
            cout << vec[i ] << endl;
            if (!valid[i]){
                ret += s[i];
            }
        }
//        cout << "ret:" << ret <<endl;
        return ret;
    }


    int minSwaps(string s) {
        s = remove_valid(s);
        return dfs(0,0,s);

    }
};