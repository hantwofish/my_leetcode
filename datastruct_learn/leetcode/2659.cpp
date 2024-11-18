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
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long tiems = 0;
        for(int i =0; i< nums.size();i++){
            que.push(nums[i]);
        }
        while(!nums.empty()){
            if(nums[0] == que.top()){
                deleteFrontNum(nums);
                que.pop();
            }else{
                moveFrontNum(nums);
            }
            tiems++;
        }
        cout << "times= " << tiems << endl;
        return tiems;
    }
private:
    void deleteFrontNum(vector<int>& nums)
    {
        if(!nums.empty()){
            nums.erase(nums.begin());
        }
    }
    void moveFrontNum(vector<int>&nums)
    {
        int frontVal = nums[0];
        for(int j =1; j < nums.size(); j++){
            nums[j-1] = nums[j];
        }
        nums[nums.size()-1] = frontVal;
    }
private:
    priority_queue<int,vector<int>,greater<int>> que; // 小顶堆
};

int mainFunc()
{
    Solution s1;
    vector<int> nums = {3,4,-1};
    s1.countOperationsToEmptyArray(nums);
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