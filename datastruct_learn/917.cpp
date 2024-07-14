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
    string reverseOnlyLetters(string s) {
        int frontIndex = 0;
        int endIndex = s.size()-1;
        while(frontIndex < endIndex){
            while(frontIndex < endIndex && !isChar(s[frontIndex])){
                frontIndex++;
            }
            while(endIndex > frontIndex && !isChar(s[endIndex])){
                endIndex--;
            }
            
            if(frontIndex < endIndex){
                swap(s[frontIndex], s[endIndex]);
                frontIndex++;
                endIndex--;
            }
        }
        cout << "str= " << s << endl;
        return s;

    }
    bool isChar(char c)
    {
        if(c >= 'a' && c <= 'z') return true;
        if(c >= 'A' && c <= 'Z') return true;
        return false;
    }
};

int mainFunc()
{
    Solution s1;
    string  s = "a-bC-dEf-ghIj";
    s1.reverseOnlyLetters(s);

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