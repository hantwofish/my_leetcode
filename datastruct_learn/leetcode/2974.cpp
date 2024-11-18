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
    vector<int> numberGame(vector<int>& nums) {
        vector<int>resu(nums.size(), 0);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i=i+2){
            resu[i] = nums[i+1];
            resu[i+1] = nums[i];
        }
        MyPrintOne(resu);
        return resu;
    }
};

int mainFunc()
{
    Solution s1;
    vector<int>nums= {5,4,2,3};
    s1.numberGame(nums);

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