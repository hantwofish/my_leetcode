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
    string losingPlayer(int x, int y) {
        int times = 0;
        while( x > 0 && y >= 4){
            times++;
            x--;
            y -= 4;
        }
        cout << "times= " << times << endl;
        if(times % 2 == 0){
            return "Bob";
        }
        return "Alice";
    }
};

int mainFunc()
{
    Solution s1;
    string resu =  s1.losingPlayer(4,11);
    cout << "resu =" << resu << endl;

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