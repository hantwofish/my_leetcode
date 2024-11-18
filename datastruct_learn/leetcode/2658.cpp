#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>

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
    int findMaxFish(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        visited.resize(N*M, false);
        UnionFind u1(N*M);
        for(int i = 0; i < N;i++){
            for(int j = 0; j < M;j++){
                if(grid[i][j] == 0) continue;
                int idx = i*M +j;
                myMap[idx] = {i, j};
                // if(visited[idx]) continue;
                visited[idx] = true;
                
                // 上下左右
                if( index_is_vaild(i, j + 1, N,M) ){
                    if(grid[i][j+1] != 0){
                        u1.unionNode(idx,i*M +j+1 );
                        visited[i*M +j+1] = true;
                    }
                }
                if( index_is_vaild(i, j -1, N,M) ){
                    if(grid[i][j-1] != 0){
                        u1.unionNode(idx,i*M +j-1 );
                        visited[i*M +j-1] = true;
                    }
                }
                if( index_is_vaild(i -1, j, N,M) ){
                    if(grid[i-1][j] != 0){
                        u1.unionNode(idx,(i-1)*M +j);
                        visited[(i-1)*M +j] = true;
                    }
                }
                if( index_is_vaild(i + 1, j, N,M) ){
                    if(grid[i+1][j] != 0){
                        u1.unionNode(idx,(i+1)*M +j);
                        visited[(i+1)*M +j] = true;
                    }
                }

            }
        }
        int maxVal = 0;
        for(int i = 0 ; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == 0) continue;
                int father_index = u1.find_fa(i*M+j);
                cout << "i= " << i << " j= " <<j << " father= " << father_index << endl;
                myMapVal[father_index] += grid[i][j];
                maxVal = max(maxVal, myMapVal[father_index]);
            }
        }


        return maxVal;
    }
    bool index_is_vaild(int i, int j, int N, int M)
    {
        if(i < 0 || i >= N || j< 0|| j >= M){
            return false;
        }
        return true;
    }


private:
    unordered_map<int, pair<int,int>>myMap;
    vector<bool>visited;
    unordered_map<int, int>myMapVal;
};

int mainFunc()
{
    Solution s1;
    vector<vector<int>>vec ={{0,0,3},{2,9,3}};
    s1.findMaxFish(vec);

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