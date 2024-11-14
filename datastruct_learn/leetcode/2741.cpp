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
    int specialPerm(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long resu = 0;
        long long MOD = 1e10 + 7;
        do{
            if(isVaILD(nums)){
                resu++;
                if(resu > MOD){
                    resu = resu % MOD;
                }
            }
        }while(next_permutation(nums.begin(), nums.end()));
        cout << "resu  =" << resu << endl;
        return resu;
    }
    bool isVaILD(vector<int>&nums)
    {
        for(int i = 0; i< nums.size() -1; i++){
            if(nums[i] % nums[i+1] == 0 || nums[i+1] % nums[i] == 0){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};

int mainFunc()
{
    Solution s1;
    vector<int>nums ={1,5,3};
    s1.specialPerm(nums);

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