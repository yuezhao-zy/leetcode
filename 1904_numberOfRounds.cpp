#include "iostream"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

class Solution {
public:

    int to_int(string & s_time){
        return (s_time[0]-'0')*10+(s_time[1]-'0');
    }

    int to_min(string & s_time){
        string s_h,s_m;
        int i_h,i_m;
        s_h = s_time.substr(0,s_time.find(':'));
        s_m = s_time.substr(s_time.find(':')+1);
        i_h = to_int(s_h);
        i_m = to_int(s_m);
        return i_h*60+i_m;
    }

    int to_appro(int min,bool upper = false){
        int appro_min = min/15*15;
        int remaining = min-appro_min;
        if (not upper)
            return appro_min;
        else if(remaining > 0){
            return appro_min + 15;
        }else{
            return appro_min;
        }
    }

    int numberOfRounds(string startTime, string finishTime) {
        int start_min = to_min(startTime), end_min = to_min(finishTime);
        cout << start_min << " " << end_min << endl;
        if (end_min <= start_min){
            end_min = 24*60+end_min;
        }
        start_min = to_appro(start_min, true);
        end_min = to_appro(end_min,false);
        cout << start_min << " " << end_min << endl;
        return max((end_min-start_min)/15,0);
    }
};