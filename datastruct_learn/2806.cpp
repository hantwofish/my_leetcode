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
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int roundedAmount  = (purchaseAmount / 10) * 10 ;
        if(abs(roundedAmount - purchaseAmount) < abs((roundedAmount + 10) - purchaseAmount)) {
            return 100 - roundedAmount;
        }else{
            return 100 - (roundedAmount + 10);
        }
        return 0;
    }
};

int mainFunc()
{
    Solution s1;
    int a = 10;
    int resyu = s1.accountBalanceAfterPurchase(a);
    cout << "resi= " << resyu << endl;

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