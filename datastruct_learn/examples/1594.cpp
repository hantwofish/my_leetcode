#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
// #include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int>>min_vec(M,vector<int>(N,-1));
        vector<vector<int>>max_vec(M,vector<int>(N,1));
        for(int i = 0; i< M; i++){
            min_vec[i][0]= grid[i][0];
            max_vec[i][0]= grid[i][0];            
        }
        for(int j = 0; j< N; j++){
            min_vec[0][j]= grid[0][j];
            max_vec[0][j]= grid[0][j];            
        }
        vector<vector<int>>director = {{0,1},{1,0}};

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(i ==0 && j ==0 ) continue;
                int min_val = INT32_MAX;
                int max_val = INT32_MIN;
                for(int k = 0; k < director.size(); k++){

                    int left = i - director[k][0];
                    int right = j - director[k][1];

                    if(left >= 0 && left < M && right >=0 && right < N){
                        int val = min( min_vec[left][right]*grid[i][j],  max_vec[left][right]*grid[i][j]);
                        min_val = min(min_val, val);

                        val = max( min_vec[left][right]*grid[i][j],  max_vec[left][right]*grid[i][j]);
                        max_val = max(max_val, val);
                    }
                }
                min_vec[i][j] =  min_val;
                max_vec[i][j] =  max_val;

            }
        }

        MyPrintTwo(min_vec);
        MyPrintTwo(max_vec);

        if(min_vec[M-1][N-1]< 0 && max_vec[M-1][N-1]< 0){
            return -1;
        }
        

        return max(min_vec[M-1][N-1],max_vec[M-1][N-1]);
    }
};

int main()
{
    Solution s1;
    // vector<vector<int>> grid = {{1,-2,1},{1,-2,1},{3,-4,1}};
    // vector<vector<int>> grid = {{-1,-2,-3},{-2,-3,-3},{-3,-3,-2}};
vector<vector<int>> grid = {{1,3},{0,-4}};
    s1.maxProductPath(grid);

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp