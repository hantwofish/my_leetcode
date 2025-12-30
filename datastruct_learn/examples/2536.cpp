#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>grid(n,vector<int>(n, 0));
        for(int i = 0; i < queries.size(); i++){
            int row1 = queries[i][0];
            int col1 = queries[i][1];
            int row2 = queries[i][2];
            int col2 = queries[i][3];
            add_one(grid, row1, row2, col1,col2 );
        }
        return grid;

    }
    void add_one(vector<vector<int>>&grid, int i_start, int i_end, int j_start, int j_end)
    {
        for(int i = i_start; i <= i_end; i++){
            for(int j =j_start; j <= j_end; j++){
                grid[i][j] += 1;
            }
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