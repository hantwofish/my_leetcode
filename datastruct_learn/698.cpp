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
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        deque<int>que;
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size();i++){
            allSum += nums[i];
            que.push_back(nums[i]);
        }
        if(allSum % k != 0) return false;
        int sumTemp =  allSum / k;

        while(!que.empty()){
            int fontVal = que.front();
            int backVal = que.back();
            if(backVal == sumTemp) {
                que.pop_back();
                continue;    
            }
            if(fontVal +  backVal == sumTemp){
                que.pop_back();
                que.pop_front();
                continue;
            }else if(fontVal +  backVal > sumTemp){
                return false;
            }else{
                int curSum = fontVal +  backVal;
                while(curSum != sumTemp){
                    

                }

            }
            return false;
        }
        return true;

    }
private:
    int allSum = 0;
};

int mainFunc()
{
    Solution s1;
    vector<int>nums = {1,2,3,4};
    int k = 3;
    bool flag = s1.canPartitionKSubsets(nums,k);
    cout << "resu = " << flag <<endl;

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