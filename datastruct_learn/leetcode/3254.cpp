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
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>resu;
        for(int i = 0; i< nums.size() - (k-1); i++){
            int temp = maxNum(nums, i, i +k -1);
            cout << "start= " << i << " end= " << i +k -1 << " val= " << temp << endl;
            resu.push_back(temp);
        }
        return resu;
    }
    int maxNum(vector<int>&nums, int start, int endIndex)
    {
        int maxnum = nums[start];
        for(int i = start +1; i<= endIndex ;i++){
            if(nums[i] - nums[i-1]  != 1){
                return -1;
            }
            maxnum =  max(maxnum, nums[i]);
        }
        return maxnum;

    }
};

int mainFunc()
{
    Solution s1;
    vector<int> nums = {1,3,4};
    int k = 2;
    s1.resultsArray(nums, k);

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