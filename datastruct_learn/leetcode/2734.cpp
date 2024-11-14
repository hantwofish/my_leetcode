#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    // std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << endl;
    cout << "[error] timer " <<  seconds << " is over exit " << endl;
    exit(1);
}


/*
找到第一个不为a 的位置，开始替换
直到遇到a 结束
*/
class Solution {
public:
    string smallestString(string s) {
        string resu =s ;
        int lastAindex = 0;
        int firsetNotA =  -1; // 第一个不为a 的位置
        
        for(int i = 0; i< resu.size(); i++){
            if(firsetNotA == -1 && resu[i] != 'a'){
                firsetNotA = i;
            }

            if(firsetNotA != -1){
                break;
            }
        }
        cout << "firsetNotA = " << firsetNotA << endl;

        if(firsetNotA == -1){ // 全是a
            resu[resu.size()-1] ='z';
            return resu;
        }
        for(int i = firsetNotA ; i< resu.length();i++){
            if(resu[i] == 'a'){
                break;
            }
            resu[i] = resu[i]-1;
        }
        
        cout << "resu= " << resu << endl;
        return resu;
    }
};

int mainFunc()
{
    Solution s1;
    string s = "aaa";
    s1.smallestString(s);

    return 0;
}

int main()
{
    std::cout << "[info] Starting timer for " << TIMEINTERVAL << " seconds" << std::endl << std::endl;
    std::thread timer_thread(timer_function, TIMEINTERVAL); // 设置计时器延时 TIMEINTERVAL 秒

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    timer_thread.join(); // 等待计时器线程完成
    std::cout << "[info] Timer thread finished" << std::endl;
    return 0;
}