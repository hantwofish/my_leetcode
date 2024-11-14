#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;



class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        int N = time.size();
        long long left_time = 0;
        long long right_time = (long long)totalTrips * time[0];
        long long resu = right_time;
        while(left_time <= right_time){
            long long cur_time = (left_time + right_time) /2;
            if(cur_time_complete(cur_time, time, totalTrips)){
                resu = min(resu, cur_time);
                right_time =  cur_time -1;
            }else{
                left_time = cur_time + 1;
            }
        }
        cout << "resu = " << resu << endl;
        return resu;
    }
    bool cur_time_complete(long long cur_time, vector<int>& time, int totalTrips)
    {
        long long all_trips = 0;
        for(int i = 0; i < time.size(); i++){
            all_trips += (cur_time / time[i]);
        }
        cout << "cur_time = " << cur_time << " all_trips= "  << all_trips << " totalTrips= " << totalTrips << endl;
        if(all_trips >= totalTrips ){
            cout << "ok " << cur_time << endl;
            return true;
        }
        return false;
    }
};
int mainFunc()
{
    Solution s1;
    vector<int> time = {1,2,3}; 
    int totalTrips = 5;
    s1.minimumTime(time, totalTrips);

    return 0;
}

int main()
{

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe