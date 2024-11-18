#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    // std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << endl;
    cout << "[error] timer " <<  seconds << " is over exit " << endl;
    exit(1);
}



class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        M = matrix.size(); //M 行 N列
        N = matrix[0].size();
        visited.resize(M, vector<int>(N,0));
        searched.resize(M, vector<int>(N,0));
        for(int i = 0; i< M;i++){
            for(int j= 0; j < N; j++){
                if(searched[i][j]) continue;
                cur = 1;
                temp.clear();
                dfs(i,j, matrix);
                cout << "i = " << i << " j= " << j << " cur= " << cur << endl;
            }
        }
        
        cout << "resu = " << resu << endl;
        MyPrintOne(res_vec);
        return resu;
    }
    void dfs(int cur_i, int cur_j, vector<vector<int>>& matrix)
    {
        // cout << "cur_i= " << cur_i << " cur_j= " << cur_j << endl;
        for(int i = 0; i< 4; i++){
            int next_i = cur_i + direction[i][0];
            int next_j = cur_j + direction[i][1];
            if(next_i < 0 || next_i >= M || next_j < 0 || next_j >= N){
                continue;
            }
            if(matrix[next_i][next_j] <= matrix[cur_i][cur_j]){
                if(visited[next_i][next_j] == 1) continue;
                continue;
            }
            if(visited[next_i][next_j] == 1) continue;
            
            // printf("    matrix[%d][%d] = %d \n", next_i, next_j,  matrix[next_i][next_j]);

            searched[next_i][next_j] = 1;

            temp.push_back(matrix[next_i][next_j]);
            visited[next_i][next_j] = 1;
            cur++;
            resu = max(resu,cur);
            if(temp.size()> res_vec.size()){
                res_vec = temp;
            }

            dfs(next_i, next_j, matrix);

            visited[next_i][next_j] = 0;
            cur--;
            temp.pop_back();
        
        }

    }
private:
    vector<vector<int>>visited;
    int M,N;
    int resu = 1;
    int cur = 1;
    vector<vector<int>>direction = {
        {0,1}, {0,-1}, {-1,0},{1,0}
    };
    vector<int>res_vec;
    vector<int>temp;

    vector<vector<int>>searched;
};

int mainFunc()
{
    Solution s1;
    // vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};

     vector<vector<int>> matrix = {{3,4,5},{3,2,6},{2,2,1}};
    s1.longestIncreasingPath(matrix);

    return 0;
}

int main()
{
    std::cout << "[info] Starting timer for " << TIMEINTERVAL << " seconds" << std::endl << std::endl;
    std::thread timer_thread(timer_function, TIMEINTERVAL); // 设置计时器延时 TIMEINTERVAL 秒

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    timer_thread.join(); // 等待计时器线程完成
    std::cout << "[info] Timer thread finished" << std::endl;
    return 0;
}