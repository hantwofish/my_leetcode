#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

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
    int maximumPrimeDifference(vector<int>& nums) {
        int left = -1;
        int right = nums.size();
        for(int i =0; i< nums.size();i++){
            if(isNum(nums[i])){
                left = i;
                break;
            }
        }
        if(left == -1) return 0;
        for(int i =nums.size()-1; i >=0;i--){
            if(isNum(nums[i])){
                right = i;
                break;
            }
        }

        int resu = 0;
        if(right - left > 0){
            resu = right -left;
        }
        return resu;
    }

    bool isNum(int num)
    {
        if(num < 2) return false;
        for(int i = 2; i< num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
};

int mainFunc()
{
    Solution s1;

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