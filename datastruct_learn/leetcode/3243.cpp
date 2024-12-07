#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"


using namespace std;
#define INVAILD_NUM (INT32_MAX/ 2)

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        figureData.resize(n, vector<int>(n, INVAILD_NUM));
        MyPrintTwo(figureData);
        for(int i = 0; i< n -1; i++){
            figureData[i][i+1] = 1;
        }
        vector<int>resu;
        for(int i = 0; i< queries.size();i++){
            figureData[queries[i][0]][queries[i][1]] = 1;
            vector<int>temp=  dijkstra( n,  figureData, 0);
            cout << " distance= " << temp[n-1] << endl;
            resu.push_back(temp[n-1]);
        }


        return resu;
    }
private:
    // Dijkstra 单源最短路」 x 到其他节点的最短路径
    vector<int> dijkstra(int n, vector<vector<int>>& figureData, int x)
    {
        vector<int>visited(n, 0);
        vector<int>distance(n, INVAILD_NUM);
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

private:
    vector<vector<int>>figureData;

};

int main()
{
    Solution s1;
    // int n = 5;
    // vector<vector<int>>queries = {{2, 4}, {0, 2}, {0, 4}};

    int n = 4;
    vector<vector<int>>queries = {{0, 3}, {0, 2}};


    s1.shortestDistanceAfterQueries(n, queries);
   cout << "[info] main end" << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe