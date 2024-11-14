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
    int wateringPlants(vector<int>& plants, int capacity) {
        stepTimes = 0;
        curCapacity = capacity;
        for(int i =0; i< plants.size(); i++){
            int needCap = plants[i];
            if(curCapacity >= needCap){
                stepTimes++;
                cout << "    i= " << i << " " << 1 << endl;
                curCapacity -= needCap;
            }else{
                cout << "not i= " << i << " " << (i+1) << endl;
                stepTimes = stepTimes + (i+1) + i;
                curCapacity = capacity;
                curCapacity -= plants[i];
            }
        }
        cout << "stepTimes= " << stepTimes << endl;
        return stepTimes;
    }
private:
    int stepTimes = 0;
    int curCapacity = 0;
};

int mainFunc()
{
    Solution s1;
    vector<int> plants = {7,7,7,7,7,7,7};
    int capacity = 8;
    s1.wateringPlants(plants, capacity);

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