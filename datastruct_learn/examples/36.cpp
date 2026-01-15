#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N =9;
        // 验证每行
        for(int i = 0; i < N; i++){
            if(row_col_is_vaild(board[i]) == false) return false;
        }
        // 验证每列
        for(int j = 0; j < N; j++){
            vector<char>temp;
            for(int i = 0; i < N; i++){
                temp.push_back(board[i][j]);
            }
            if(row_col_is_vaild(temp) == false) {
                return false;
            }
        }
        // 验证每个单矩阵
        for(int i = 0; i < N; i=i+3){
            for(int j = 0; j < N; j=j+3){
                bool flag = matrix_is_vaild(board, i, i+2, j, j+2);
                if(flag == false){
                    return false;
                }
            }
        }

        return true;

    }
private:
    bool matrix_is_vaild(vector<vector<char>>& board, int start_row, int end_row, int start_col, int end_col)
    {
        unordered_map<char,int>my_map;
        for(int i = start_row; i <= end_row; i++){
            for(int j = start_col; j <= end_col; j++){
                if(board[i][j] >= '0' && board[i][j] <= '9'){
                    my_map[board[i][j]]++;
                    if(my_map[board[i][j]] > 1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool row_col_is_vaild(vector<char>&nums)
    {
        int N = 10;
        vector<int>visited(N, 0);
        for(int i =0; i < N; i++ ){
            if( nums[i] < '0' || nums[i] > '9'){
                continue;
            }
            int val = char_2_val(nums[i]);
            if(visited[val] == 1){
                return false;
            }else{
                visited[val] = 1;
            }
        }
        return true;

    }
    int char_2_val(char cur_char)
    {
        
        
        return cur_char - '0' + 0;
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