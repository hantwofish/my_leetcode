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
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i, j;
        aCurTimes = 0;
        aCurVal = capacityA;
        bCurTimes = 0;
        bCurVal = capacityB;

        for(i= 0 , j = plants.size()-1 ; i<= j; i++, j--){
            cout << "i= " << i << " val= " << aCurVal << " j= " << j << " val= " << bCurVal << endl;
            if(i == j){
                if(aCurVal >= bCurVal){
                    if(aCurVal < plants[i]){
                        aCurTimes++;
                    }else{
                        aCurVal -= plants[i];
                    }
                }else{ // 选择B 进行浇灌
                    if(bCurVal >= plants[j]){
                        bCurVal -= plants[j];
                    }else {
                        bCurVal = capacityB;
                        bCurVal -= plants[j];
                        bCurTimes++;
                    }
                }
                continue;
            }
            if(aCurVal >= plants[i]){
                aCurVal -= plants[i];
            }else {
                aCurVal = capacityA;
                aCurVal -= plants[i];
                aCurTimes++;
            }
            if(bCurVal >= plants[j]){
                bCurVal -= plants[j];
            }else {
                bCurVal = capacityB;
                bCurVal -= plants[j];
                bCurTimes++;
            }
        }
        cout << "aCurTimes= " << aCurTimes << " bCurTimes= " << bCurTimes << endl;
        return aCurTimes + bCurTimes;
    }
private:
    int aCurVal;
    int aCurTimes;
    int bCurVal;
    int bCurTimes;    
};

int mainFunc()
{
    Solution s1;
    vector<int> plants = {7,7,7,7,7,7,7};
    int capacityA = 7;
    int capacityB = 8;
    s1.minimumRefill(plants, capacityA, capacityB);

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