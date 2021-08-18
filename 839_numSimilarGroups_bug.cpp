#include "bits/stdc++.h"
#include "iostream"
using namespace std;

const int max_n=3*1e2+1;
int level[max_n];
int root[max_n];

void print_vec(vector<int> & vec){
    for(int i : vec)
        cout << i << " ";
    cout << endl;
}
class Solution {
public:

    int find(int x){
        return x == root[x] ? x : (root[x] = find(root[x]));
    }

    void merge(int x,int y){
        cout << "merge" << x <<" " << y << endl;
        int rx = find(x),ry = find(y);
        if(level[rx] <= level[ry]){
            root[rx] = ry;
        }else
            root[ry] = rx;
        if(level[rx] == level[ry] and rx != ry)
            level[ry] ++;
    }

    void init(int n){
        for(int i = 0;i < n;i ++){
            level[i] = 1;
            root[i] = i;
        }
    }

    void find_similar(vector<string> & strs){
        for(int i = 0;i < strs.size();i ++){
            for(int j = 0;j < strs.size();j ++){
                if (i == j or strs[i].length() != strs[j].length() or find(i) == find(j))
                    continue;
                string s1 = strs[i], s2 = strs[j];
                if(s1 == s2){
                    merge(i,j);
                    continue;
                }
                bool is_similar = false;
                for(int s = 0; s < s1.length();s ++){
                    for(int e = s+1; e < s1.length();e ++){
                        char tmp = s1[s];
                        s1[s] = s1[e];
                        s1[e] = tmp;
                        if (s1 == s2){
                            merge(i,j);
                            is_similar = true;
                            s1[e] = s1[s];
                            s1[s] = tmp;
                            break;
                        }
                        s1[e] = s1[s];
                        s1[s] = tmp;
                    }
                    if (is_similar)
                        break;
                }

            }

        }

    }


    int numSimilarGroups(vector<string>& strs) {
        init(strs.size());
        find_similar(strs);
        unordered_set<int> ans_root;
        for(int i = 0;i < strs.size();i ++){
            cout << i << " " << find(i) << endl;
            ans_root.insert(find(i));
        }
        return ans_root.size();

    }
};


int main(){







}