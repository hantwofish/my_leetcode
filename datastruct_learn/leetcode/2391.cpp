#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>

#define TIMEINTERVAL 1

using namespace std;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    // std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << endl;
    cout << "[error] timer " <<  seconds << " is over exit " << endl;
    exit(1);
}



class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        GetLastINdex(garbage);
        for(int i= 0; i< 3; i++){
            cout << lastIndex[i] << endl;
        }

        int resu = 0;
        for(int i =0; i< 3; i++){
            if(lastIndex[i] == -1) continue;
            for(int j =0; j < lastIndex[i]; j++){
                resu = resu + travel[j];
            }
        }
        for(int i = 0; i< garbage.size();i++){
            resu += garbage[i].length();
        }
        cout << "resu= " << resu << endl;
        return resu;
    }
    void GetLastINdex(vector<string>& garbage)
    {
        for(int i =0 ; i< 3; i++){
            lastIndex[i] = -1;
        }
        for(int i = garbage.size()-1; i>= 0; i--){
            if(lastIndex[0] != -1 &&lastIndex[1] != -1 &&lastIndex[2] != -1){
                return;
            }
            cout << "i= " << i << endl;
            if( lastIndex[0] == -1 && garbage[i].find("M") != string::npos){
                cout << "M i= " << i << endl;
                lastIndex[0] = i;
            }
            if( lastIndex[1] == -1 && garbage[i].find("P") != string::npos){
                cout << "P i= " << i << endl;
                lastIndex[1] = i;
            }
            if( lastIndex[2] == -1 && garbage[i].find("G") != string::npos){
                cout << "G i= " << i << endl;
                lastIndex[2] = i;
            }
        }

    }
private:
    int lastIndex[3] = {0};
};

int mainFunc()
{
    Solution s1;
    // vector<string>garbage = {"G","P","GP","GG"};
    // vector<int>travel = {2,4,3};
    vector<string>garbage = {"MMM","PGM","GP"};
    vector<int>travel = {3,10};
    s1.garbageCollection(garbage,travel);

    return 0;
}

int main()
{
    std::cout << "[info] Starting timer for " << TIMEINTERVAL << " seconds" << std::endl << std::endl;
    std::thread timer_thread(timer_function, TIMEINTERVAL); // 设置计时器延时 TIMEINTERVAL 秒

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    timer_thread.join(); // 等待计时器线程完成
    std::cout << "[info] Timer thread finished" << std::endl;
    return 0;
}