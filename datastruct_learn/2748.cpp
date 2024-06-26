#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <math.h>
#include <cmath>

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
    int countBeautifulPairs(vector<int>& nums) {
        int resu = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+ 1; j < nums.size(); j++){
                int a = nums[i];
                while(a >= 10){
                    a = a / 10;
                }
                int b = nums[j];
                while(b >= 10){
                    b = b % 10;
                }

                

                // if(isGcd(a, b)){
                //     resu++;
                // }
                // 最大公约数 互质
                if(__gcd(a,b)==1){
                    printf("[%d, %d] [%d %d] [%d %d] \n",i, j, nums[i],nums[j], a,b);
                    resu++;
                }
            }
        }
        cout << "resu = " << resu << endl;
        return resu;
        
    }
    int Gcd(int m,int n)
     {
        int o;
        while(n>0)
        {
            o=m%n;
            m=n;
            n=o;
        }
        return m;
     }
    bool isGcd(int x , int y)
    {
        int a = max(x, y);
        int b = min(x, y);
        int val = 1;
        for(int i = 1; i<= b ; i++){
            if(a % i == 0 && b % i ==0){
                val = max(val, i);
            }
        }
        if(val == 1){
            cout << "a= " << a << " b= " << b << endl;
            return true;
        }
        return false;
    }
};

int mainFunc()
{
    Solution s1;
    vector<int>nums = {31,25,72,79,741};
    s1.countBeautifulPairs(nums);

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