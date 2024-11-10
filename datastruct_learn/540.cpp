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
    int singleNonDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0; i< nums.size(); i++){
            cout <<"i= " << i << " vsal= " << nums[i] << endl;

        }
        // int i =0;
        int N = nums.size();
        for(int i = 0; i<= N-1; i = i+2){
            if(i == N-1){
                return nums[i];
            }
            if(nums[i] != nums[i+1]){
                cout << "i= " << i <<  "val " << nums[i] << " "<<  nums[i+1] << endl;
                return nums[i];
            }
        }
        
        return nums[0];
    }
};

int mainFunc()
{
    vector<int>nums = {1,1,2,3,3,4,4,8,8};
    Solution s1;
    s1.singleNonDuplicate(nums);

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