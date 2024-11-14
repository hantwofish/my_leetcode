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
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        for(int a = 0; a < sqrt(c) ;a++){
            int b = sqrt(c - a * a);
            cout << "a= " << a << " b= " << b << endl;
            if(a*a + b * b == c){
                cout << "result a= " << a << " b= " << b << endl;
                return true;
            }
        }
        return false;
    }
};

int mainFunc()
{
    Solution s1;
    s1.judgeSquareSum(134);

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