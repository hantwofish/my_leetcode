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
    int pivotIndex(vector<int>& nums) {
        if(nums.size()== 1){
            return 0;
        }

        vector<int>leftSum(nums.size(), 0);
        vector<int>rightSum(nums.size(),0);
        for(int i = 1; i< nums.size(); i++){
            leftSum[i] = leftSum[i-1] + nums[i-1];
        }
        for(int i = nums.size() -2; i>= 0; i--){
            rightSum[i] = rightSum[i+1] + nums[i+1];
        }
        MyPrintOne(leftSum);
        MyPrintOne(rightSum);

        for(int i = 0; i< nums.size(); i++){
            if(leftSum[i] == rightSum[i]){
                return i;
            }
        }



        return -1;
    }   
};

int mainFunc()
{
    Solution s1;
    vector<int>nums = {1,7,3,6,5,6};
    s1.pivotIndex(nums);

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