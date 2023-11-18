#include"../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<set>
#include<unordered_set>

#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>
#include <iterator>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        pair<int, int>ans(INT32_MAX/2, -1);
        vector<vector<int>>mp(n, vector<int>(n, INT32_MAX/2));
        for(auto &eg: edges){
            int from = eg[0];
            int to =   eg[1];
            int weight = eg[2];
            mp[from][to]= weight;
            mp[to][from]= weight;
        }
        for(int k =0; k < n; k++){
            mp[k][k] = 0;
            for(int i = 0; i < n; i++){
                for(int j= 0; j< n; j++){
                    // 得到每两个点直接的最短路径
                    mp[i][j] = min(mp[i][j], mp[i][k]+ mp[k][j]);
                }
            }
        }
        MyPrintTwo(mp);
        for(int i = 0; i< n; i++){
            int cnt = 0;
            for(int j =0; j < n; j++){
                if(mp[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= ans.first){
                ans = {cnt, i};
            }
        }



        return ans.second;
    }
    // 计算两个节点之间的最短路径
    int calAllNeighbor(int start, int end)
    {
        queue<int>que;
        int distance = 0;
        que.push(start);
        while(1){

        }


        

    }

    void initData(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        nodeNum =n;
        limitDistance = distanceThreshold;
        isVisited.resize(n,false);
        figureData.resize(n,vector<int>(n,0));
        for(int i =0; i < edges.size(); i++){
            int start = edges[i][0];
            int end = edges[i][1];
            int weight = edges[i][2];
            figureData[start][end] = weight;
            figureData[end][start] = weight;
        }
        MyPrintTwo(figureData);
    }
public:
    int nodeNum;
    int limitDistance;
    vector<vector<int>>figureData;
    unordered_map<int, vector<int>>digNodeDis;
    vector<bool>isVisited;
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    int n = 4;
    vector<vector<int>>edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}}; 
    int distanceThreshold = 4;
    int resuIndex= s1.findTheCity(n,edges,distanceThreshold);
    cout << "resuIndex= " << resuIndex << endl;

    cout << "hello" << endl;
    return 0;
}