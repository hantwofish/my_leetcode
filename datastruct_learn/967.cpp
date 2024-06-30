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



class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {

        backTracing(0,"", n,k);
        vector<int>resu;
        for(int i = 0; i < resu_vec.size(); i++){
            resu.push_back(stoi(resu_vec[i]));
        }
        return resu;

    }
    void backTracing(int cur_i, string cur_val, int n, int k)
    {
        if(cur_i >= n){
            cout << "cur_val = " << cur_val << endl;
            resu_vec.push_back(cur_val);
            return;
        }
        // 当前位于 cur_index 位置时该做什么, 判断填入的数字是啥
        for(int i =0; i<= 9; i++){
            if(cur_i == 0 && i ==0 ) continue;
            if( cur_i == 0){
                cur_val = cur_val + to_string(i);
                backTracing(cur_i +1, cur_val, n, k);
                // cur_val = cur_val.substr(0, cur_val.size()-1);
                cur_val.pop_back();
            }else{
                int lastVal = (cur_val[cur_val.size()-1]) - '0';
                if( abs(i - lastVal) == k){
                    backTracing(cur_i +1, cur_val + to_string(i), n, k);
                }
            }
        }

    }
private:
    vector<string> resu_vec;
};

int mainFunc()
{
    Solution s1;
    int n = 3;
    int k =7;
    s1.numsSameConsecDiff(n,k);
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