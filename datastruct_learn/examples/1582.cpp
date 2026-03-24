#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
// #include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int result = 0;
        int M = mat.size();
        int N = mat[0].size();
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(mat[i][j] == 1 & row_and_col_ok(mat, i, j)){
                    result++;
                }
            }
        }
        return result;

    }
    int row_and_col_ok(vector<vector<int>>& mat, int row, int col)
    {
        int M = mat.size();
        int N = mat[0].size();
        //  行
        for(int j = 0; j < N; j++){
            if( j == col) continue;
            if(mat[row][j] == 1) return 0;
        }
        for(int i = 0; i < M; i++){
            if(i == row) continue;
            if(mat[i][col] == 1) return 0;
        }
        return 1;
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