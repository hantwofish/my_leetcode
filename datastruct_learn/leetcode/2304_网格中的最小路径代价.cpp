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
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        const int N = grid.size();
        const int M = grid[0].size();
        int allNum = N * M;
        figureData.resize(allNum, vector<int>(allNum, INT_MAX/ 2));

        for(int i =0; i< grid.size(); i++){
            for(int j = 0; j < grid[0].size();j++){
                mpNumlocation[grid[i][j]] = make_pair(i,j);
            }
        }

        makeData(grid,moveCost);
//        MyPrintTwoVec(figureData);

//        cout <<"--------" << endl;
        GetAllDis(figureData);

        vector<vector<int>>disatance = GetAllDis(figureData);
        int  resu = INT_MAX;
//        cout << "M = "  <<  M << endl;
        for(int i = 0; i< M; i++){
            int start = grid[0][i];
            for(int j = 0; j < M; j++){
                int end = grid[N-1][j];
//                cout << "stat= " << start << " end= " <<  end <<endl;
                resu = min(resu, disatance[start][end] + end);
            }
        }


        return  resu;
    }
    vector<vector<int>> GetAllDis(vector<vector<int>> &figureData)
    {
        int N = figureData.size();
//        vector<vector<int>>disTance(N,vector<int>(N,INT_MAX));

        vector<vector<int>>disTance= figureData;
        for(int nodeNum = 0; nodeNum < N; nodeNum++){
            disTance[nodeNum][nodeNum] = 0;
            for(int i = 0; i<N; i++){
                for(int j = 0; j <N; j++){
                    // 得到每两个点直接的最短路径
                    disTance[i][j] = min(disTance[i][j], disTance[i][nodeNum]+ disTance[nodeNum][j]);
                }

            }
        }
//        cout <<" ---  " << endl;
//        MyPrintTwoVec(disTance);
//        cout <<" ---  " << endl;

        return  disTance;

    }
    pair<int,int> findNumIndex(vector<vector<int>>& grid, int num)
    {
        pair<int, int> resu = {0,0};
        // for(int i = 0; i<grid.size(); i++){
            // for(int j = 0; j <grid[0].size(); j++){
                // if(grid[i][j] == num){
                    // resu.first = i;
                    // resu.second = j;
                // }
            // }
        // }
        resu = mpNumlocation[num];
        return  resu;
    }
    void makeData(vector<vector<int>>& grid, vector<vector<int>>& moveCost)
    {
        for(int i = 0;i <moveCost.size(); i++){
            for(int j = 0; j< moveCost[0].size(); j++){
                int startNode = i;
                pair<int,int>index = findNumIndex(grid, i);
                int row = index.first;
                int nextRow = row + 1;
                if(nextRow >= grid.size()){ // 最后一行
//                    cout <<"netRow = " << nextRow << " size= " << grid.size() <<endl;
                    continue;
                }
//                cout <<"i= " << i << " " << index.first << " " <<index.second  <<" nextRoe= " << nextRow << endl;
                int endNode = grid[nextRow][j];
//                cout << "strat= " << startNode << " end= " <<endNode <<endl;
                figureData[startNode][endNode] = i + moveCost[i][j];
            }
        }
    }
public:
    vector<vector<int>> figureData;
    unordered_map<int,pair<int,int>>mpNumlocation;
};

int main()
{
    Solution s1;
    

    cout << "hello" << endl;
    return 0;
}