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
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>resuVec;
        int N = code.size();
        for(int i = 0; i < code.size(); i++){
            int resu = 0;
            cout << "i= " << i << endl;
            if(k < 0){
                for(int j = i-1; j >= i + k; j--){
                    cout << "i= " << i << " j= " << j << endl;
                    if(j < 0){
                        resu += code[j + N];
                    }else{
                        resu += code[j];
                    }
                }
            }else if(k > 0){
                for(int j = i+ 1; j <= i + k; j++){
                    if(j >=N){
                        resu += code[j - N];
                    }else{
                        resu += code[j];
                    }
                }
            }
            cout << "resu= " << resu << endl;
            resuVec.push_back(resu);
        }
        return resuVec;
    }
};

int mainFunc()
{
    Solution s1;
vector<int> code = {2,4,9,3};
 int k = -2;
 s1.decrypt(code, k);
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