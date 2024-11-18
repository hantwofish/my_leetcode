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
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int resu = 0;
        int front = 1;
        int end = 0;

        while(front < temperatureA.size()){
            int A = 0;
            int B = 0;

            if(temperatureA[front] > temperatureA[front -1]){
                A = 1;
            }else if(temperatureA[front] == temperatureA[front -1]){
                A = 0;
            }else{
                A = -1;
            }

            if(temperatureB[front] > temperatureB[front -1]){
                B = 1;
            }else if(temperatureB[front] == temperatureB[front -1]){
                B = 0;
            }else{
                B = -1;
            }

            cout << " a= " << A << " B= " << B << " front= " << front << " end= " << end << endl;
            if(A == B ){
                
              
                resu = max(front -end , resu);
                
                
            }else{
                
                end = front;
            }
            front++;
            

        }

        cout << "resi ="  << resu << endl;
        return resu;
    }
};

int mainFunc()
{
    Solution s1;
    // ] temperatureB = []
    vector<int> temperatureA = {21,18,18,18,31};
    vector<int> temperatureB = {34,32,16,16,17};
    s1.temperatureTrend(temperatureA, temperatureB);

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