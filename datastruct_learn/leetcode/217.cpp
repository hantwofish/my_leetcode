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



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i =0; i< nums.size(); i++){
             myMap[nums[i]]++;

            if(myMap[nums[i]] >= 2){
                cout << "true " << endl;
                return true;
            }

        }
        cout << "false " << endl;
        return false;
    }
private:
    unordered_map<int,int>myMap;
};

int mainFunc()
{
    Solution s1;
    vector<int>nums = {1,2,3,4};
    s1.containsDuplicate(nums);

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