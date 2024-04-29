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
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        int endIndex = 0;
        if(nums.size() % 2 == 0){
            endIndex  = nums.size() -2;
        }else{
            endIndex = nums.size() -1;
        }
        vector<int>data(nums.size(), 0);

        int times = 0;
        int highStartInex =  1;
        while(highStartInex < nums.size() ){
            data[highStartInex] = nums[times];
            times++;
            highStartInex += 2;
        }

        times = nums.size() -1;
        while(endIndex >= 0){
            data[endIndex] = nums[times];
            endIndex -= 2;
            times--;
        }
        MyPrintOne(data);
        nums =data;
        return;
    }
};

int mainFunc()
{
    Solution s1;
    vector<int> nums = {1,5,1,1,6};
    // vector<int> nums = {1,3,2,2,3,1};
    s1.wiggleSort(nums);
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