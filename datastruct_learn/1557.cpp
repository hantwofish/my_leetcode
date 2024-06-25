#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "TREE.h"

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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++){
            int fromVal = edges[i][0];
            int toVal = edges[i][1];
            firMap[toVal]++;
        }
        vector<int>resu ;
        for(int i = 0; i < n; i++){
            if(firMap[i] == 0){
                resu.push_back(i);
            }
        }
        return resu;
    }
public:
    unordered_map<int, int>firMap;
};

int mainFunc()
{
    Solution s1;
    int n = 6;
    vector<vector<int>>edges = {{0,1},{0,2},{2,5},{3,4},{4,2}};

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