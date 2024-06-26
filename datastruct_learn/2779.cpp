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
    int maximumBeauty(vector<int>& nums, int k) {
        int resu = 0;
        for(int i = 0; i< nums.size(); i++){
            int val = nums[i];
            for(int j = nums[i]-k; j <= nums[i]+ k; j++){
                myMap[j]++;
                cout  << "myMap[j] = " << myMap[j] << endl;
                resu = max(resu, myMap[j]);
            }
        }
        // int resu = 0;
        // auto it = myMap.begin();
        // while(it != myMap.end()){
        //     // cout << it->first << " = " << it->second << endl;
        //     resu = max(resu, it->second);
        //     it++;
        // }
        return resu;
    }
private:
    unordered_map<int,int>myMap;
};

int mainFunc()
{
    Solution s1;
    vector<int> nums = {4,6,1,2};
    int k = 2;
    s1.maximumBeauty(nums,k);

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