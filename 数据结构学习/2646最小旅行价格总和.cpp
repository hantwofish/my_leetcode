#include"../STLCOMMON.h"
#include"../COMMONALO.h"
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
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        N = n;
        numCount.resize(N,0);
        figure.resize(N);
        isVisited.resize(N,false);

        MakefigureInfo(n,edges,price,trips);
        PrintTWoFigure();


        for(int i = 0; i < trips.size(); i++){
            int startNum = trips[i][0];
            int endNum = trips[i][1];
            isVisited.resize(N,false);
            numCount[startNum]++;
            numCount[endNum]++;
            DFSCalTracNum(startNum, endNum, startNum);
        }
        MyPrintOne(numCount);

        return 0;
    }
    void MakefigureInfo(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips)
    {
        for(int i = 0; i< edges.size(); i++){
            int startnum  = edges[i][0];
            int endNum = edges[i][1];
            figure[startnum].push_back(endNum);
            figure[endNum].push_back(startnum);
        }
        cout << "MakefigureInfo " << endl;

    }
    // DfS
    void DFSCalTracNum(int startNum, int endNum, int cur)
    {
        if(cur == endNum) {
            
            return;
        }
        numCount[cur]++;
        if(isVisited[cur]) return;

        isVisited[cur] = true;
        vector<int>neighHord = figure[cur];
        for(int i = 0; i < neighHord.size(); i++){
            DFSCalTracNum(cur,endNum, neighHord[i]);
        }
    }
    void PrintTWoFigure()
    {
        for(int i = 0; i < figure.size(); i++){
            for(int j = 0; j < figure[i].size();j++){
                cout << figure[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
public:
    int N =0;
    vector<int>numCount; // 存储每个节点经过 的次数
    vector<vector<int>>figure; // 临接表
    vector<bool>isVisited;
};



int main()
{
    Solution s1;
    int n  = 4;
    vector<vector<int>>edges = {{0,1},{1,2},{1,3}};
    vector<int>price = {2,2,10,6};
    vector<vector<int>>trips = {{0,3},{2,1},{2,3}};
    s1.minimumTotalPrice(n,edges,price,trips);
    

    cout << "hello word 2" << endl;
    return 0;
}

