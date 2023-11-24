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

// 临接矩阵
class Solution1{
public:
    int calMaxArray(int& n, vector<vector<int>>&nums)
    {
        N = n+1; // n = 9; N=10;
        dataArray.resize(N, vector<int>(N,10000)); // 不联通为超大数值
        isVisited.resize(N,false);
        

        for(int i= 0; i< nums.size(); i++){
            int start = nums[i][0];
            int end = nums[i][1];
            dataArray[start][end] = dataArray[end][start] = 1;
        }
        MyPrintTwo(dataArray);
        // int start =1
        // BFS_Search(start);
        // DFS_Search(start);
        CalAllDistance(dataArray);
        
        return 0;
    }
    void CalAllDistance(vector<vector<int>>&figureInfo)
    {
        int nodNum = N; // 节点个数
        vector<vector<int>>minDistance = figureInfo; // 计算两个节点之间最小距离
        int startNodeIndex = 1;
        for(int k =startNodeIndex; k < nodNum; k++){
            minDistance[k][k] = 0;
            for(int i = startNodeIndex; i < nodNum; i++){
                for(int j= startNodeIndex; j< nodNum; j++){
                    // 得到每两个点直接的最短路径
                    minDistance[i][j] = min(minDistance[i][j], minDistance[i][k]+ minDistance[k][j]);
                }
            }
        }
        MyPrintTwo(minDistance);
    }
    void BFS_Search(int start)
    {
        // 从任意一个节点开始BFS 遍历

        queue<int>myQue;
        myQue.push(start);
        isVisited[start] = true;
        while(!myQue.empty()){
            int top  = myQue.front();
            myQue.pop();
            cout << "top= " << top << endl;
            // 将相邻的加入队列
            for(int i = 1; i< N; i++){
                if(isVisited[i]){
                    continue;
                }
                if(dataArray[top][i] != 1){
                    continue;
                }
                myQue.push(i);
                isVisited[i] = true;
            }
        }

    }

    void DFS_Search(int cur)
    {
        if(isVisited[cur]==  true){
            return;
        }
        // 访问当前
        {
            cout << "cur= " << cur << endl;
            isVisited[cur] = true;
        }

        // 遍历相邻的
        for(int i =1 ; i<N ; i++){
            if(isVisited[i]){
                continue;
            }
            if(dataArray[cur][i] != 1){
                continue;
            }
            DFS_Search(i);

        }

    }

public:
    vector<vector<int>>dataArray;
    vector<bool>isVisited;
    int N =0;
};

// 临接表s
class Solution{
public:
    int calMaxArray(int& n, vector<vector<int>>&nums)
    {
        int N = n + 1;
        isVisited.resize(N, 0);
        for(int i = 0; i< nums.size();i++){
            int start = nums[i][0];
            int end = nums[i][1];
            figureMap[start].push_back(end);
            figureMap[end].push_back(start);
        }
        PrintMap();
        int start = 1;
        // BFSSearch(start);
        DFSSearch(start);


        return 0;
    }
    void BFSSearch(int start)
    {
        queue<int>myQue;
        myQue.push(start);
        isVisited[start] = true;
        while(!myQue.empty()){
            int top = myQue.front();
            cout << "top = " << top << endl; // 访问
            myQue.pop();

            // 
            vector<int>neighbor = figureMap[top];
            for(int i = 0; i< neighbor.size();i++){
                int nodeIndex = neighbor[i];
                if(isVisited[nodeIndex]== true){
                    continue;
                }
                myQue.push(nodeIndex);
                isVisited[nodeIndex] = true;
            }
        }
    }
    void DFSSearch(int cur)
    {
        if(isVisited[cur]){
            return;
        }
        {
            cout<< "cur= " << cur << endl;
            isVisited[cur] = true;
        }
        vector<int>neighbor = figureMap[cur];
        for(int i = 0; i< neighbor.size();i++){
            int nei = neighbor[i];
            if(isVisited[nei] == true){
                continue;
            }
            DFSSearch(nei);
        }
    }

    void PrintMap()
    {
        auto it = figureMap.begin();
        while(it!= figureMap.end()){
            cout << it->first << " -> ";
            vector<int>temp = it->second;
            for(int k = 0; k < temp.size(); k++){
                cout << temp[k] << " ";
            }
            cout << endl;
            it++;
        }
    }

public:
    map<int,vector<int>>figureMap;
    int N = 0;
    vector<bool>isVisited;
};

int main()
{
    Solution1 s1;
    int N = 9;
    vector<vector<int>>nums ={
        {1,2},{1,3},{1,4},
        // {2,3},
        {2,5},
        {2,6},
        {3,7},
        {4,8},{4,9},
        // {6,7},
    };
    s1.calMaxArray(N,nums);

    // MyPrintOne(nums[0]);
    

    cout << "hello" << endl;
    return 0;
}