#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;


class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()== 1) return true;
        int sum = nums[0] % 2 ;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] %2 + sum == 1){
                sum = nums[i] %2;
            }else{
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

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe