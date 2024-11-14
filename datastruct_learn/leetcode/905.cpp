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
    vector<int> sortArrayByParity(vector<int>& nums) {
        int front = 0;
        int end = nums.size()-1;
        while(front < end){
            cout << "front " << front << " end= " << end << endl;
            while( front < end && nums[front] % 2 == 0){
                front++; 
            }
            // front 指向的为 奇数
            while( end > front && nums[end] % 2== 1){
                end--;
            }
            // front 指向的为 偶数
            if(front < end){
                swap(nums[front], nums[end]);
            }
            

        }
        return nums;
    }
};

int mainFunc()
{
    Solution s1;
    vector<int> nums = {1,2,3,4};
    vector<int>resu = s1.sortArrayByParity(nums);
    MyPrintOne(resu);
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