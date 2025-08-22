#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        // dp.resize(M, vector<int>(N,0));
        // // 考虑一行 一列的情况
        // if(grid[0][0] == 0){
        //     dp[0][0] = 0;
        // }else{
        //     dp[0][0] = 1;
        // }
        // //
        // for(int i = 1; i < M; i++){
        //     for(int j = 1; j < N;j++){
        //         if(grid[i][j] == 0) continue;

        //         dp[i][j] = min(dp[i-1][j], dp[i][j-1]) +1;

        //     }
        // }

        // MyPrintTwo(dp);
        // return dp[M-1][N-1];

        // 找出最右侧的一
        int result =0;
        int right_one = 0;
        int left_one = N-1;
        int up_one = M-1;
        int down_one = 0;
        for(int i =0 ; i < M; i++){
            for(int j = 0; j< N; j++){
                if(grid[i][j] == 0) continue;
                right_one = max(right_one, j);
                left_one  = min(left_one, j);
                up_one  = min(up_one, i);
                down_one = max(down_one, i);
                cout << "i= "<< i << " j= " << j  << " | " << up_one << " " << down_one << " " << left_one << " "<< right_one <<endl;

              result = max( result, (down_one-up_one+1) *(right_one-left_one +1));

            }
        }
        

        cout << "result= " << result << endl;
        return result;
    }
private:
    vector<vector<int>>dp;
    int N;
    int M;
};


int main()
{
    vector<vector<int>>grid = {{0,1,0},{1,0,1}};
    Solution s1;
    s1.minimumArea(grid);

   cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe