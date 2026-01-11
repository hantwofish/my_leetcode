#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int>>visited(M,vector<int>(N,0));
        
        int cycle = 0;
        while(cout_num < M * N){
            cout << "cycle =  "<< cycle << endl;
            int start_row = 0 + cycle;
            int end_row = M -1 - cycle;
            int start_col = 0 + cycle;
            int end_col = N -1 -cycle;

            

            // 右
            int cur_row = start_row;
            int cur_col = start_col;
            while(cur_col <= end_col){
                if(visited[cur_row][cur_col] == 0){
                    result.push_back(matrix[cur_row][cur_col]);
                    visited[cur_row][cur_col] = 1;
                    cout << matrix[cur_row][cur_col] << " " ;
                }
                
                cur_col++;
                cout_num++;
            }
        
            // 下
            cur_row = start_row + 1;
            cur_col = end_col;
            while(cur_row <= end_row){
                if(visited[cur_row][cur_col] == 0){
                    result.push_back(matrix[cur_row][cur_col]);
                    visited[cur_row][cur_col] = 1;
                    cout << matrix[cur_row][cur_col] << " " ;
                }
                cur_row++;
                cout_num++;
            }
              
            // 左
            cur_row = end_row;
            cur_col = end_col -1;
            while(cur_col >= start_col){
                if(visited[cur_row][cur_col] == 0){
                    result.push_back(matrix[cur_row][cur_col]);
                    visited[cur_row][cur_col] = 1;
                    cout << matrix[cur_row][cur_col] << " " ;
                }
                cur_col--;
                cout_num++;
            }
               
            // 上
            cur_row = end_row -1;
            cur_col = start_col;
            while(cur_row >= start_row + 1){
                if(visited[cur_row][cur_col] == 0){
                    result.push_back(matrix[cur_row][cur_col]);
                    visited[cur_row][cur_col] = 1;
                    cout << matrix[cur_row][cur_col] << " " ;
                }
                cur_row--;
                cout_num++;
            }

            
            cout << endl;

            cycle++;
           

        }
        return result;
    }
private:
    int cout_num = 0;
    vector<int>result;
    
};


int main()
{

    Solution s1;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    s1.spiralOrder(matrix);
    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp