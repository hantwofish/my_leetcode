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
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0; i< arr.size() ;i++){
            for(int j = i+1; j < arr.size(); j++){
                if(arr[i] == arr[j]* 2 || arr[j] == arr[i] *2){
                    return true;
                }
            }
        }
        return false;

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