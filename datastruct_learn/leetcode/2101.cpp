#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;


class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        N =  bombs.size();
        figureData.resize(N, vector<long long>(N, 0));
        visited.resize(N, 0);
        for(int i = 0; i< bombs.size(); i++){
            for(int j = i+1; j < bombs.size(); j++){
                long long dis1= abs(  bombs[i][0] - bombs[j][0] );
                long long dis2= abs(  bombs[i][1] - bombs[j][1] );

                long long distance = dis1 * dis1 + dis2 * dis2;
                figureData[i][j] = distance;
                figureData[j][i] = distance;
                // cout <<"i=" <<i <<"j =" <<j <<" " <<figureData[i][j] <<endl;
            }
        }

        // for(int i = 0; i<N; i++){
        //     for(int j = 0; j <N ; j++){
        //         cout <<"i=" <<i <<"j =" <<j <<" " <<figureData[i][j] <<endl;
        //     }

        // }

    

        int resyu = 0;
        for(int i = 0; i< N; i++){
            resyu = max(resyu,maxNUm(i, bombs) );
            if(resyu == N) break;
        }
        
        return resyu;

    }

    int maxNUm(int start, vector<vector<int>>& bombs)
    {
        while(!que.empty()){
            que.pop();
        }
        visited.clear();
        visited.resize(N, 0);
        int resu = 0;
        // cout << "start= " << start << endl;

        que.push(start);
        // cout << "       push " << start << endl;
        visited[start] = 1;
        while(!que.empty()){
            int front = que.front();
            for(int i = 0; i< N; i++){
                if(visited[i]) continue;
                // if(figureData[start][i] < pow(bombs[start][2] + bombs[i][2] , 2)  ){
                if(figureData[front][i] <= pow(bombs[front][2]  , 2)  ){
                    que.push(i);
                    // cout << "       push " << i << endl;
                    visited[i] = true;
                }

            }
            que.pop();
            // cout << "pop " << front  << endl;
            resu++;
        }
        // cout << "start= " << start << " resu = " << resu << endl;
        return resu;
    }

private:
    int N = 0;
    vector<vector<long long>>figureData;
    vector<int>visited;
    queue<int>que;
};
// [[82,62,6],
// [56,90,7],
// [30,90,3],
// [36,9,7],
// [38,79,10],
// [16,36,6],
// [23,71,4],
// [55,77,1],
// [87,54,7],
// [37,28,9],
// [46,73,6],
// [67,87,6],
// [24,39,7],
// [6,46,3]]



int mainFunc()
{
    Solution s1;
    // vector<vector<int>> bombs = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    vector<vector<int>> bombs = {{82,62,6},{56,90,7},{30,90,3},{36,9,7},{38,79,10},{16,36,6},{23,71,4},{55,77,1},{87,54,7},{37,28,9},{46,73,6},{67,87,6},{24,39,7},{6,46,3}};
    s1.maximumDetonation(bombs);
 
    return 0;
}

int main()
{

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe