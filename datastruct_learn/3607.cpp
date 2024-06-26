#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
// #include "TREE.h"

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
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int N = edges.size() + 1;
        NodNum = N;
        firgureMap.resize(N,vector<int>(N, INT32_MAX /2));
        for(int i = 0; i< edges.size();i++){
            firgureMap[edges[i][0]][edges[i][1]] = edges[i][2];
            firgureMap[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        MyPrintTwo(firgureMap);

        CalDiS(3);
    }

    vector<int>CalDiS(int startNode)
    {
        vector<int>dis(NodNum, 0);
        vector<int>visitesd(NodNum, 0);
        visitesd[startNode] = 1;
        DFS(startNode, startNode, dis, visitesd);
        MyPrintOne(dis);
    }
private:
    vector<vector<int>>firgureMap;

    void DFS(int startNode,  int curNode, vector<int>&dis, vector<int>&visitesd)
    {
        for(int i = 0; i< NodNum; i++){
            if(firgureMap[curNode][i] == INT32_MAX /2) continue;
            if(visitesd[i]) continue;
            // if(curNode == startNode) continue;

            visitesd[i] = true;
            dis[i] =  dis[curNode] + firgureMap[curNode][i];
            cout<< "i =" << i << " " << dis[i] << endl;
            DFS(startNode, i, dis, visitesd);
            
        }



    }
    int NodNum ;

};

int mainFunc()
{
    Solution s1;
    vector<vector<int>> edges = {{0,6,3},{6,5,3},{0,3,1},{3,2,7},{3,1,6},{3,4,2}};
    int signalSpeed = 3;
    s1.countPairsOfConnectableServers(edges,signalSpeed);

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