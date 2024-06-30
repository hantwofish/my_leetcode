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
    int findTargetSumWays(vector<int>& nums, int target) {
        visited.resize(nums.size(), 0);
        // DFS(0, nums[0], nums, target);
        // DFS(0, -1* nums[0], nums, target);
        DFS(0, 0, nums, target);
        cout << "resu= " << resu_choices << endl;
        return resu_choices;
    }
    // 当前位于 cur_index 位置时该做什么
    void DFS(int cur,int curSum, vector<int>& nums, int target)
    {
        
        if(curSum == target && cur >= nums.size() ){
            resu_choices++;
            cout << "resu  cur= " << cur <<" cursum = " << curSum <<endl;
            return;
        }
        if(cur >= nums.size()) return;

        cout << "cur= " << cur <<" cursum = " << curSum <<endl;
        for(int i =0 ;i < 2; i++){
            
            // if(visited[cur + 1]) continue;

            curSum +=  (direction[i] *  nums[cur]);
            // visited[cur+1] = true;

            DFS(cur + 1, curSum, nums, target);

            // visited[cur+1] = false;
            curSum -= (direction[i] *  nums[cur]);
        }
        
        
    }
private:
    vector<int>direction ={1,-1};
    vector<int>visited;
    int resu_choices = 0 ;
};

int mainFunc()
{
    Solution s1;
    vector<int>nums = {1,1,1,1,1};
    int target = 3;
    s1.findTargetSumWays(nums, target);

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