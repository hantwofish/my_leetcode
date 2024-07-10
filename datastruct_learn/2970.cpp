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
    int incremovableSubarrayCount(vector<int>& nums) {
        int resuTimes = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int length = 0; length < nums.size() -i; length++){
                if(isIncrease(nums, i ,i + length)){
                    resuTimes++;
                }
            }
        }
        cout << "resu = " << resuTimes << endl;
        return resuTimes;
    }
private:
    bool isIncrease(vector<int>&nums, int delete_i,int delete_j)
    {
        bool resu = true;
        int lastNum = INT32_MIN;
        int len = nums.size();
        delete_j = min(delete_j, len-1);
        cout << "erase " << delete_i << " " << delete_j << endl;
        for(int i = 0; i < nums.size(); i++){
            if(i >= delete_i && i <= delete_j) continue;
            if(nums[i] <= lastNum) return false;
            lastNum = nums[i];
        }
        return resu;
    }
};

int mainFunc()
{
    Solution s1;
    vector<int>nums = {8,7,6,6};
    s1.incremovableSubarrayCount(nums);

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