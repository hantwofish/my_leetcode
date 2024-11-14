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
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>>resu(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i= 0; i< grid.size();i++){
            for(int j = 0; j< grid[0].size();j++){
                resu[i][j] = getDiffNum(grid, i,j);
            }
        }
        return resu;
    }
private:
    int getDiffNum(vector<vector<int>>& grid, int curI,int curJ)
    {
        set<int>forntLeft;
        set<int>behindRight;
        for(int i = curI +1, j= curJ+1; i< grid.size() && j < grid[0].size() ; i++,j++){
            behindRight.insert(grid[i][j]);
        }
        for(int i = curI-1, j= curJ-1; i>=0 && j>=0; i--,j--){
            forntLeft.insert(grid[i][j]);
        }

        return abs((int)(forntLeft.size()) - (int)(behindRight.size()));
    }
private:

};

int mainFunc()
{
    Solution s1;

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