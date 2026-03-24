#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
// #include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>zero_nums;
        for(int i = 0; i< matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    zero_nums.push_back({i,j});
                }
            }
        }
        for(int i = 0; i < zero_nums.size(); i++){
            int row = zero_nums[i].first;
            int col = zero_nums[i].second;
            set_row_col_zero(matrix, row, col);

        }
        return;

    }
    void set_row_col_zero(vector<vector<int>>& matrix, int row, int col)
    {
        int M = matrix.size();
        int N = matrix[0].size();
        for(int j = 0; j <N; j++ ){
            matrix[row][j] = 0;
        }
        for(int i = 0 ; i < M; i++){
            matrix[i][col] = 0;
        }
    }

};

int main()
{

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp