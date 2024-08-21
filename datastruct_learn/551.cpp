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
    bool checkRecord(string s) {
        bool ret = true;
        int A_num = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'A'){
                A_num++;
                if(A_num >= 2) return false;
            }else if(s[i] == 'L'){
                if(i+2 <= s.size()-1 &&  s[i+1] == 'L' && s[i+2] == 'L') return false;
            }
        }
        return true;
    }
};

int mainFunc()
{
    Solution s1;
    string s = "PPALLL";
    bool rets = s1.checkRecord(s);
    cout << "resu= " << rets << endl;

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