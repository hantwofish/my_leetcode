#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
// #include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int start_row = x;
        int end_row = x + k -1;
        int start_col = y;
        int end_col = y + k -1;

        cout << "start_row= " <<  start_row << " " << end_row << " col =" << start_col << " " << end_col << endl;
        for(int i = start_row; i < start_row +  k /2  ;i++){
            int row_diff = end_row;
            end_row--;
            cout << "i= " << i << " row_diff= " << row_diff << endl;

            vector<int>temp ;
            for(int j = start_col; j <= end_col; j++){
                temp.push_back(grid[i][j]);
                cout << " " << grid[i][j];
            }
            cout << "x " << endl;

            for(int j = start_col; j <= end_col; j++){
                grid[i][j]= grid[row_diff][j];
                cout << " " << grid[i][j];
            }
            cout << "y " << endl;

            int k =0;
            for(int j = start_col; j <= end_col; j++){
                grid[row_diff][j] = temp[k];
                k++;
                cout << " " << grid[i][j];
            }
            cout << "z " << endl;
        }

        MyPrintTwo(grid);

        return grid;
    }
};

int main()
{
    // vector<vector<int>> grid = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // int x = 1, y = 0, k = 3;

    vector<vector<int>> grid = {{3,4,2,3},{2,3,4,2}};
    int x = 0, y = 2, k = 2;
    Solution s1;
    s1.reverseSubmatrix(grid,x, y,k);
    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp