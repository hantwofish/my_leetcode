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
    int maxHeightOfTriangle(int red, int blue) {
        int num1= redon(red, blue);
        int num2= blueon(red, blue);
        cout << "num1= " << num1 << "  num2= " << num2 << endl;
        return max(num1, num2);
    }   
    int redon(int red, int blue)
    {
        int resu = 0;
        int row = 1;
        while (red >= 0 && blue >= 0)
        {
            if(red >= row){
                red -= row;
                resu++;
                row++;
            }else{
                return resu;
            }

            if(blue >= row){
                blue -= row;
                resu++;
                row++;
            }else{
                return resu;
            }
        }
        return resu;
    }

    int blueon(int red, int blue)
    {
        int resu = 0;
        int row = 1;
        while (red >= 0 && blue >= 0)
        {
            if(blue >= row){
                blue -= row;
                resu++;
                row++;
            }else{
                return resu;
            }

            if(red >= row){
                red -= row;
                resu++;
                row++;
            }else{
                return resu;
            }
        }
        return resu;
    }
};

int mainFunc()
{
    Solution s1;
    cout << "hello " << endl;

    s1.maxHeightOfTriangle(2,4);

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