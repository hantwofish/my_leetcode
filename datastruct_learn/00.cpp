#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>

#define TIMEINTERVAL 6

using namespace std;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << "timer " <<  seconds << " is over exit " << endl;
    exit(1);
}



class Solution{
public:
    void printAll()
    {
        while(1){

        }
    }
};

int mainFunc()
{
    Solution s1;

    return 0;
}

int main()
{
    std::cout << "Starting timer for " << TIMEINTERVAL << " seconds" << std::endl;
    std::thread timer_thread(timer_function, TIMEINTERVAL); // 设置计时器延时 TIMEINTERVAL 秒

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "main end" << endl;
        return 0;
    }

    timer_thread.join(); // 等待计时器线程完成
    std::cout << "Timer thread finished" << std::endl;
    return 0;
}