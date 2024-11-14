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
    int minimumMoves(vector<vector<int>>& grid) {
        int resu = 0;
        while(!isFillALl(grid)){

            int i, j , flag;
            flag = 0;
            for(i = 0; i < 3; i++){
                for(j = 0; j< 3; j++){
                    if(grid[i][j] == 0) {
                        flag = 1;
                        break;
                    }
                }
                if(flag) break;
            }
            cout << "i= " << i << " j= " << j << endl;
            int dele_i, dele_j;
            int distanc = INT32_MAX;
            for(int ii = 0; ii < 3; ii++){
                for(int jj = 0; jj < 3; jj++){
                    if(grid[ii][jj] > 1) {
                        int tempdis =  abs(i - ii) + abs( j - jj);
                        if(tempdis < distanc){
                            distanc = tempdis;
                            dele_i =  ii;
                            dele_j =  jj;
                        }
                    }
                }
            }
            printf("[%d, %d] -- [%d, %d] \n", i, j, dele_i, dele_j);
            grid[dele_i][dele_j] -= 1;
            grid[i][j]++;
            resu = resu + abs(dele_i -i) + abs(dele_j -j);

        }
        cout << "resu= " << resu << endl;
        return resu;
        
    }
    bool isFillALl(vector<vector<int>>& grid)
    {
        for(int i = 0; i< 3; i++){
            for(int j = 0; j < 3; j++){
                if(grid[i][j] == 0){
                    return false;
                }
            }
        }
        return true;
    }
};

int mainFunc()
{
    Solution s1;
    vector<vector<int>>grid = {{1,3,0},{1,0,0},{1,0,3}};
    s1.minimumMoves(grid);
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