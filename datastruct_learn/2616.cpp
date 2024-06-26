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
    int minimizeMax(vector<int>& nums, int p) {
        if(p ==0 ) return 0;
        sort(nums.begin(), nums.end());
        int resu = INT32_MAX;
        

        for(int start = 0; start < nums.size(); start++){
            vector<int>oneVec;
            for(int i = start; i< start + 2*p ;i=i+2){
                if(i +1 >= nums.size()){
                    break;;
                }
                oneVec.push_back(abs(nums[i] - nums[i+1]  ));
                cout << "start = " << start << " 1 resu = " << abs(nums[i] - nums[i+1]  ) << endl;
            }
            sort(oneVec.begin(), oneVec.end(), greater<int>());
            if( oneVec.size( ) == p){
                resu = min(resu, oneVec[0]); 
            }
        }

        cout << "resu = " << resu << endl;
        return resu;
    }
};

int mainFunc()
{
    Solution s1;
    vector<int> nums = {4,1,3,3,0,4,3};
    int p = 1;
    s1.minimizeMax(nums, p);

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