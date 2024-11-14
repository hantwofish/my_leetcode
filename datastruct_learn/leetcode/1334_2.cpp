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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        N = n;
        // figureDistance.resize(N, vector<int>(N , INVALID_VAL));
        figureData.resize(N, vector<int>(N , INVALID_VAL));
        for(int i = 0; i< edges.size();i++){
            figureData[edges[i][0]][edges[i][1]] = edges[i][2];
            figureData[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        MyPrintTwo(figureData);
        // CalDistanceOfAllNode(figureData);
        for(int i= 0; i< N;i++){
            figureDistance.push_back(dijkstra(n,figureData, i));
        }

        MyPrintTwo(figureDistance);

        int resu = -1;
        int times = INT32_MAX;
        for(int i = 0; i< N;i++){
            int curtimes =0;
            for(int j = 0; j < N;j++){
                if(i == j) continue;
                if(figureDistance[i][j] <= distanceThreshold){
                    curtimes++;
                }
            }
            cout << "i= " << i << " curtimes= " << curtimes << endl;
            if(curtimes <= times && i >  resu){
                times = curtimes;
                resu = i;
            }
        }
        cout << "resu = " << resu << endl;
        return resu;
    }
private:
        // Dijkstra 单源最短路」 x 到其他节点的最短路径
    vector<int> dijkstra(int n, vector<vector<int>> figureData, int x)
    {
        vector<int>visited(n, 0);
        vector<int>distance(n, INVALID_VAL);
        distance[x] =  0;
        for(int k =0 ;k< n; k++){
            // 每次找到 [最短距离最小] 且 [未被更新] 的点 t
            int t = -1;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && (t == -1 || distance[i] < distance[t])){
                    t = i;
                } 
            }

            visited[t] = 1; // 节点t 标记为已更新
            // 用 t 去更新 其他点
            for(int i = 0; i< n; i++){
                distance[i] = min(distance[i], distance[t] + figureData[t][i]); 
            }
        }
        return distance;
    }
    void CalDistanceOfAllNode(vector<vector<int>>&figureData)
    {
        figureDistance = figureData;
        for(int k = 0; k < N;k++){
            for(int i = 0; i < N;i++){
                for(int j = 0; j < N;j++){
                    if(figureDistance[i][k] < INVALID_VAL && figureDistance[k][j] < INVALID_VAL && 
                        figureDistance[i][j] > figureDistance[i][k ]  + figureDistance[k][j]){
                        figureDistance[i][j] = figureDistance[i][k ]  + figureDistance[k][j];
                    }
                }
            }
        }

    }
    
private:
    vector<vector<int>>figureData;
    int N = 0;
    int INVALID_VAL = 0x3f3f3f3f;
    vector<vector<int>>figureDistance;
};

int mainFunc()
{
    Solution s1;
    // int n = 4;
    // vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    // int distanceThreshold = 4;
    int n = 6;
    vector<vector<int>> edges = {{0,3,7},{2,4,1},{0,1,5},{2,3,10},{1,3,6},{1,2,1}};
    int distanceThreshold = 417;
    

    s1.findTheCity(n, edges, distanceThreshold);


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