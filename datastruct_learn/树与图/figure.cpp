#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>

#include<set>
#include<unordered_set>

#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>
#include <iterator>
#include<tuple>
#include"../../STLCOMMON.h"
#include"../../COMMONALO.h"


using namespace std;


class Figure{

public:
    void makeFigure(int n, vector<vector<int>>&data)
    {
        N =n;
        figureData.resize(N,vector<int>(N, INVALID_VAL));
        visited.resize(N,0);
        for(int i = 0; i< data.size(); i++){
            int from_val = data[i][0];
            int to_val =  data[i][1];
            figureData[from_val][to_val]= 1;
            figureData[to_val][from_val]= 1;
        }
        MyPrintTwo(figureData);
        
    }
    // 计算任意两点之间的最短距离
    void floyd(int n, vector<vector<int>>&figureData)
    {
        // figureDistance = figureData;
        for(int k = 0; k < n;k++){
            for(int i = 0; i < n;i++){
                for(int j = 0; j < n;j++){
                    if(figureData[i][k] < INVALID_VAL && figureData[k][j] < INVALID_VAL && 
                        figureData[i][j] > figureData[i][k ]  + figureData[k][j]){
                        figureData[i][j] = figureData[i][k ]  + figureData[k][j];
                    }
                }
            }
        }
    }
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

    void dfs(int cur)
    {   
        cout << "cur= " << cur << endl;
        visited[cur] = 1;
        for(int i = 0; i < N;i++){
            if(visited[i] == 0 && figureData[cur][i] != INVALID_VAL){
                dfs(i);
            }
        }
        
    }


private:
    int N ; // 节点个数
    vector<vector<int>>figureData;
    int INVALID_VAL = 0x3f3f3f3f;
    vector<int>visited;
};


int main()
{
    vector<vector<int>>data ={
        {1,3},{1,4},{4,2},{3,2},{2,5},{2,6},{5,6}
    };
    int N = 7;
    Figure s1;
    s1.makeFigure(N, data);
    s1.dfs(1);

    return 0;

}