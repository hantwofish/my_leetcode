#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 10

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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        for(int i =0; i < graph.size();i++){
            for(int j = 0; j < graph[i].size(); j++){
                figureMap[i].push_back(graph[i][j]);
            }
        }
        MyPrintMap(figureMap);
        vector<int>onePath;
        visited.resize(graph.size(), 0);
        DfsSearch(0, graph.size()-1, 0, onePath);

        for(int i =0; i< resu.size();i++){
            resu[i].insert(resu[i].begin(), 0);
        }

        return resu;
    }
    void DfsSearch(int startNode, int endNode, int curNode, vector<int>&onePath)
    {
        if(!onePath.empty() && onePath[onePath.size()-1] == endNode){
            resu.push_back(onePath);
            MyPrintOne(onePath);
            return;
        }
        vector<int>neighHord = figureMap[curNode];
        for(int i =0; i< neighHord.size(); i++){
            int nextNode =neighHord[i];
            if(visited[nextNode]) continue;

            onePath.push_back(nextNode);
            visited[nextNode] = true;
            DfsSearch(startNode, endNode, nextNode, onePath);
            onePath.pop_back();
            visited[nextNode] = false;

        }

    }
public:
    unordered_map<int, vector<int>>figureMap; //邻接表
    vector<vector<int>>resu;
    vector<int>visited;

};

int mainFunc()
{
    Solution s1;
    // vector<vector<int>> graph = {{1,2},{3},{3},{}};
    vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
    s1.allPathsSourceTarget(graph);
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