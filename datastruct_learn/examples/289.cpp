#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
// #include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {


        vector<vector<int>> board_back_up = board;
        MyPrintTwo(board_back_up);


        for(int i = 0; i< board_back_up.size(); i++){
            for(int j = 0; j < board_back_up[i].size(); j++){
                vector<int>resu= get_eight_status(board_back_up, i, j);
                board[i][j] =  live_status(resu, board_back_up[i][j]);
            }
        }
        return;
        
    }

    vector<int> get_eight_status(vector<vector<int>>& board, int row, int col)
    {
        int M = board.size();
        int N = board[0].size();
        vector<int>resu;
        vector<vector<int>>direction={
            {-1,0}, {1,0}, {0,-1},{0,1},
            {-1,-1},{1, 1},{1, -1},{-1,1}
        };
        for(int i = 0; i < direction.size();i++){
            int cur_row = row + direction[i][0];
            int cur_col = col + direction[i][1];
            if(cur_row >= 0 && cur_row <M && cur_col >=0 && cur_col <N){
                cout << "row= " << row << " col= " <<col << endl;
                resu.push_back(board[cur_row][cur_col]);
            }
        }
        
        for(int i = 0; i< resu.size(); i++){
            cout << resu[i] << " ";
        }
        cout << endl;

        return resu;
    }
    int live_status(vector<int>& resu, int live)
    {
        unordered_map<int,int>status_map;
        for(int i = 0; i< resu.size(); i++){
            status_map[resu[i]]++;
        }
        if(live == 1){
            if(status_map[1] < 2) return 0;
            if(status_map[1] == 2 || status_map[1] == 3) return 1;
            if(status_map[1] > 3) return 0;
        }else  if(live == 0){
            if(status_map[1] == 3) return 1;
        }
        
        return live;
    }
};

int main()
{
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution s1;
    s1.gameOfLife(board);
    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp