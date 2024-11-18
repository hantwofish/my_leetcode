#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>

#define TIMEINTERVAL 1

using namespace std;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    // std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << endl;
    cout << "[error] timer " <<  seconds << " is over exit " << endl;
    exit(1);
}



class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        for(int i = 0; i< tasks.size(); i++){
            myMap[tasks[i]]++; // 记录每个值的次数
        }

        int resu =0;
        auto it = myMap.begin();
        while(it != myMap.end()){
            if(it->second == 3 || it->second == 2) {
                resu++;
            }else if(it->second == 1){
                return -1;
            }else{
                int tiems = it->second;
                if(tiems % 3 == 0){
                    resu += (tiems /3);
                }else if(tiems % 3 == 2){
                    resu = resu + (tiems / 3) +1;
                }else if(tiems % 3 ==1){
                    resu = resu + (tiems / 3) +1;
                }
            }
            it++;
        }
        cout << "resu= " << resu << endl;
        return resu;
    }
    unordered_map<int, int>myMap;
};

int mainFunc()
{
    Solution s1;
    // vector<int>tasks ={2,2,3,3,2,4,4,4,4,4};
    vector<int>tasks ={2,3,3};
    int resu =  s1.minimumRounds(tasks);
    cout << "main resu = " << resu << endl;
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