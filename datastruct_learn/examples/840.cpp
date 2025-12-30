#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int M = grid.size();
        int N = grid[0].size();
        cout << "M= " << M << " N= " << N << endl;
        int i =0 ; 
        int j =0;
        int result =0 ;
        for(i = 0; i< M; i++){
            for( j  = 0; j < N; j++){
                if(pre_check(grid, i, i+2, j , j+2) == false){
                    continue;
                }
                if( check_ok(grid, i , i+2, j , j+2) == true){
                    result++;
                }
            }
        }
        cout << "result = " << result << endl;
        return result;
        
    }
    bool pre_check(vector<vector<int>>& grid, int i_start, int i_end, int j_start, int j_end)
    {
        int M = grid.size();
        int N = grid[0].size();
        if( i_start >= 0 && i_end < M && j_start >=0 && j_end < N){
            cout << "pre_check i_start= " << "(" << i_start << " " << i_end << " " << j_start << " " << j_end << endl; 
            return true;
        }
        return false;
    }
    bool check_ok(vector<vector<int>>& grid, int i_start, int i_end, int j_start, int j_end)
    {
        // cout << "check_ok i_start= " << i_start << " j_start = " << j_start << endl;
        int sum_val = 0;
        sum_val = grid[i_start][j_start+0]+ grid[i_start][j_start+1] + grid[i_start][j_start+2];
        cout << "check_ok i_start= " << i_start << " j_start = " << j_start << " sum_val= " << sum_val << endl;
        
        // 横
        for(int i = i_start ; i <= i_end; i++){
            int sum_temp = 0;
            for(int j = j_start; j<= j_end; j++){
                cout << "i= " << i  << " j= " << j << " val= " << grid[i][j] << endl;
                sum_temp += grid[i][j];

            }
            if(sum_temp != sum_val){
                return false;
            }
        }
        // 竖
        for(int j = j_start ; j <= j_end; j++){
            int sum_temp = 0;
            for(int i = i_start; i<= i_end; i++){
                sum_temp += grid[i][j];

            }
            if(sum_temp != sum_val){
                return false;
            }
        }
        // 斜
        int sum_1 = grid[i_start][j_start] + grid[i_start+1][j_start+1] + grid[i_start+2][j_start+2];
        int sum_2 = grid[i_start][j_end] + grid[i_start+1][j_end-1] + grid[i_start+2][j_end-2];
        cout << "sym_1= " << sum_1 << " sum_2= " << sum_2 << endl;
        if(sum_1 != sum_val){
            return false;
        }
        if(sum_2 != sum_val){
            return false;
        }
        cout << "i= " << i_start << " " << j_start << endl;


        vector<int>test={1,2,3,4,5,6,7,8,9};
        vector<int>test_val;
        for(int i = i_start ; i <= i_end; i++){
            for(int j = j_start; j<= j_end; j++){
               test_val.push_back(grid[i][j]);
            }

        }
        sort(test_val.begin(),test_val.end());
        if(test_val != test){
            return false;
        }
        return true;


    }
};

int main()
{

    vector<vector<int>>grid = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    Solution s1;
    s1.numMagicSquaresInside(grid);
   cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe