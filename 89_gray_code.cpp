const int max_n = (1<< 16)+1;
bool visited[max_n];
vector<int>ans;
int bitnot(int nb, int bit) {

    int value = 1-((nb & (1 << bit)) != 0);
    if (value) {
        nb |= 1 << bit;
    } else {
        nb &= ~(1 << bit);
    }
    return nb;
}


class Solution {

public:

    bool dfs(int u,int n){
        if (ans.size()==(1<<n))
            return true;
        for(int i = 0;i < n;i ++){
            int not_nb = bitnot(u,i);
            if (visited[not_nb]){
                continue;
            }
            visited[not_nb] = true;
            ans.push_back(not_nb);
            if(dfs(not_nb,n)){
                return true;
            }else{
                visited[not_nb] = false;
                ans.pop_back();
            }
        }
        return false;
    }


    vector<int> grayCode(int n) {
        fill(visited,visited+max_n,false);
        visited[0] = true;
        ans.clear();
        ans.push_back(0);
        dfs(0,n);
        return ans;


    }
};

