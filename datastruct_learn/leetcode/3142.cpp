#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;



class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int N= grid.size();
        int M = grid[0].size();
        for(int i = 0; i < N;i++){
            for(int j = 0; j < M; j++){
                if(i+1 <N && j < M ){
                    if(grid[i][j] == grid[i+1][j]){

                    }else{
                        return false;
                    }
                }
                if(i <N && j+1 < M ){
                    if(grid[i][j] != grid[i][j+1]){
                        
                    }else{
                         return false;

                    }
                }

            }
        }
        return true;
        
    }
};

int mainFunc()
{
    Solution s1;

    return 0;
}

int main()
{

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe