#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        M = grid.size();
        N = grid[0].size();
        visited.resize(M, vector<int>(N, 0));
        int search_times = 0;

        for(int i = 0; i< M; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == '0') {
                    continue;
                }
                if(visited[i][j] == 1){
                    continue;
                }
                search_times++;
                dfs(grid, i , j);
            }
        }

        cout << "SEARCH_TIME " <<search_times << endl;
        return search_times;

    }
    void dfs(vector<vector<char>>& grid, int start_row, int start_col)
    {
        if( start_row < 0 || start_row >= M || start_col < 0 || start_col >= N){
            return;
        }
        if(visited[start_row][start_col] == 1) return;

        char cur_char = grid[start_row][start_col];
        visited[start_row][start_col] = true;

        if(cur_char == '1'){
            for(int i = 0; i< 4;i++){
                int row_cur = start_row +  direction[i][0];
                int col_cur = start_col +  direction[i][1];

                dfs(grid, row_cur, col_cur);
            }
            
        }
    }
private:
    int M = 0;
    int N = 0;
    vector<vector<int>>visited;
    vector<vector<int>>direction = {{-1,0},{1,0},{0,-1},{0,1}};
};


int main()
{

    Solution s1;
    vector<vector<char>>grid = {
    // {'1','1','1','1','0'},
    // {'1','1','0','1','0'},
    // {'1','1','0','0','0'},
    // {'0','0','0','0','0'}
      {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
    } ;
    s1.numIslands(grid);
    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp