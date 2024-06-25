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
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        for(int i = 0; i< edges.size(); i++){
            if(edges[i] != -1){
                figureMap[i].push_back(edges[i]);
            }
        }

        MyPrintMap(figureMap);


        vector<bool>visited(edges.size(), 0); 
        vector<int>neighNod;
        DFS(1, visited, neighNod);
        MyPrintOne(neighNod);
        return 0;
    }
    void DFS(int curNode, vector<bool>&visited, vector<int>&neighNode)
    {
        cout << "DFS " << curNode << endl;

        vector<int>temp = figureMap[curNode];
        for(int i = 0; i < temp.size();i++ ){
            if(visited[temp[i]]) continue;
            cout << "  temp " << temp[i] << endl;

            visited[temp[i]] = true;
            neighNode.push_back(temp[i]);

            DFS(temp[i],visited, neighNode);
            // visited[temp[i]] = false;
        }
    }
private:
    unordered_map<int, vector<int>>figureMap;
};

int mainFunc()
{
    Solution s1;
    vector<int>edges = {2,2,3,-1};
    s1.closestMeetingNode(edges, 0, 1);

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