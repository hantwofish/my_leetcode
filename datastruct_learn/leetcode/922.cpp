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
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int sigNum = 1; 
        int usigNum = 0;

        
        vector<int>resu(nums.size(), 0);
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] % 2 == 0){
                resu[usigNum] = nums[i];
                usigNum += 2;
            }else{
                resu[sigNum] = nums[i];
                sigNum += 2;
            }
            cout << "i= " << i << " num= " << nums[i] << " usigNum=" << usigNum << " " << sigNum << endl;

        }

        MyPrintOne(resu);
        return resu;

    }

};

int mainFunc()
{
    Solution s1;
    vector<int>nums = {4,2,5,7};
    s1.sortArrayByParityII(nums);
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