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
    string reverseStr(string s, int k) {
        int length = s.length();
        int modVal = s.length() % (2*k);
        int delVal = s.length() / (2*k);
        for(int i = 0; i< delVal; i++){
            reverse(s.begin() + i * 2*k, s.begin() + i * 2*k + k);
        }

        int endFront = 0 + delVal * 2*k;
        if(modVal < k){
            reverse(s.begin() + endFront, s.begin() + endFront + modVal);   
        }else {
            reverse(s.begin() + endFront, s.begin() + endFront + k);   

        }
        cout << "resu = " <<  s << endl; 
        return s;
    }

};

int mainFunc()
{
    Solution s1;
    s1.reverseStr("abcd", 2);

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