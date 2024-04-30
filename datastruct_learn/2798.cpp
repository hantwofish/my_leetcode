#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>

#define TIMEINTERVAL 6

using namespace std;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    // std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << "timer " <<  seconds << " is over exit " << endl;
    exit(1);
}



class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        sort(hours.begin(), hours.end(), greater<int>());
        int times = 0;
        for(int i = 0; i< hours.size(); i++){
            if(hours[i] >= target){
                times++;
            }else{
                break;
            }
            
        }
        return times;
    }
};

int mainFunc()
{
    Solution s1;
    vector<int>hours ={0,1,2,3,4,5};
    int target = 2;
    int resu =  s1.numberOfEmployeesWhoMetTarget(hours, target);
    cout << "resu= " << resu << endl; 
    return 0;
}

int main()
{
    std::cout << "Starting timer for " << TIMEINTERVAL << " seconds" << std::endl;
    std::thread timer_thread(timer_function, TIMEINTERVAL); // 设置计时器延时 TIMEINTERVAL 秒

    cout << "------------" << endl;
    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "main end" << endl;
        cout << "------------" << endl;
        return 0;
    }
    

    timer_thread.join(); // 等待计时器线程完成
    std::cout << "Timer thread finished" << std::endl;
    return 0;
}