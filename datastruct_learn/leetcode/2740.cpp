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
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int resu = INT32_MAX;
        for(int i = 0; i< nums.size()-1; i++){

            resu = min(resu, nums[i+1] - nums[i]);
        }
        return resu;
    }
private:
    vector<int>minNum;
    vector<int>maxNum;
};

int mainFunc()
{
    Solution s1;
    vector<int>nums = {1,10,100};
    int resu = s1.findValueOfPartition(nums);
    cout << "resu= " << resu << endl;

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