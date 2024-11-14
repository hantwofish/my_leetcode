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
    vector<int> shortestToChar(string s, char c) {
        vector<int>resi(s.length(), 0);
        for(int i = 0; i< s.length();i++){
            if(s[i] == c){
                resi[i] = 0;
                continue;
            }
            int temp = INT32_MAX;
            for(int k = i -1 ;k >= 0; k--){
                if(s[k] == c){
                    temp = min(temp, abs(i - k));
                }
            }
            for(int k = i+1; k < s.length(); k++){
                if(s[k] == c){
                    temp = min(temp, abs(i - k));
                }

            }
            resi[i] = temp;
        }
        return resi;
    }
};

int mainFunc()
{
    Solution s1;
    vector<int>resu =  s1.shortestToChar("loveleetcode", 'e');
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