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
    vector<vector<int>> permute(vector<int>& nums) {
        N = nums.size();
        visited.resize(N,0);
        vector<int>temp;
        backtracing(0,nums,temp);

        return resu;
    }
    void backtracing(int cur_indx,vector<int>& nums, vector<int>&temp)
    {
        if(temp.size() == N){
            MyPrintOne(temp);
            resu.push_back(temp);
            return;
        }
        for(int i =0; i < N; i++){
            if(visited[i] == 1) continue;
            
            visited[i] = 1;
            temp.push_back(nums[i]);
            backtracing(cur_indx, nums, temp);
            visited[i] = 0;
            temp.pop_back();
        } 

    }
private:
    vector<int>visited;
    vector<vector<int>>resu;
    int N = 0;
    int K =0;
};

int mainFunc()
{
    Solution s1;
    vector<int>nums = {1,2,3};
    s1.permute(nums);

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