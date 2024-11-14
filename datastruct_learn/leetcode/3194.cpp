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
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << endl;

        double resu = nums[nums.size()-1];
        int begin = 0;
        int end = nums.size()-1;
        while(begin <= end){
            double temp = (nums[begin] + nums[end] ) / 2.0;
            cout << nums[begin] << " " << nums[end] << " " << temp << endl;
            resu = min(temp , resu);
            begin++;
            end--;
        }
        cout << "resu= " << resu << endl;
        return resu;
    }   
private:
    priority_queue<int,vector<int>,greater<int>> que1; // 小顶堆
    priority_queue<int,vector<int>> que2; // 默认顶堆
};

int mainFunc()
{
    Solution s1;
    vector<int> nums= {7,8,3,4,15,13,4,1};
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


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe