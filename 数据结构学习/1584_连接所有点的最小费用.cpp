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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        distanceArr.resize(n,vector<int>(n,0));
        isVisted.resize(n,false);
        N =n;

        for(int i = 0; i< n ;i++){
            for(int j= i + 1; j < n; j++){
                // cout << "i= " << i << " j= " << j << endl;
                int distance = calDist(points[i][0],points[i][1], points[j][0], points[j][1]);
                distanceArr[i][j] = distance;
                distanceArr[j][i] = distance;
            }
        }
        // MyPrintTwo(distanceArr);
        int resu = 0;

        set<int>mySet;
        mySet.insert(0);
        isVisted[0]= true;
        // 将0号节点放入set
        while(mySet.size() != n){
            // 从集合中找到最小代价的节点, 
            int stratIndex = 0;
            int endIndex = 0;
            int cost = 0;
            int nextnode = FindMinCostNode(mySet, stratIndex, endIndex, cost);
            if(nextnode == -1){
                cout << "err" << endl;
                return -1;
            }else{
                // cout << "stratIndex=  " << stratIndex << " endInex= " << endIndex << " cost= " << cost << endl;
            }
            mySet.insert(nextnode);
            isVisted[nextnode] = true;
            resu +=  cost;
        }



        return resu;
    }
    int FindMinCostNode(set<int>&mySet, int& re_startIndx, int& re_endIndex , int& recost)
    {
        int cost = INT32_MAX;
        int nodeIndex = -1;
        
        for(auto it = mySet.begin(); it != mySet.end(); it++ ){
            int startIndex = *it;
            for(int endIndex = 0; endIndex  < N; endIndex++){
                if(isVisted[endIndex]){
                    continue;
                }
                if(distanceArr[startIndex][endIndex] < cost){
                    cost = distanceArr[startIndex][endIndex];
                    nodeIndex = endIndex;

                    re_startIndx = startIndex;
                    re_endIndex = endIndex;
                }
            }
        }
        recost = cost;
        return nodeIndex;
    }
    int calDist(int x1, int y1, int x2, int y2)
    {
        return abs(x1-x2) + abs(y1-y2);
    }
public:
    vector<vector<int>>distanceArr;
    vector<int>isVisted;
    int N = 0;
};

int main()
{
    Solution s1;
    vector<vector<int>>points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    int resu = s1.minCostConnectPoints(points);
    cout << "resu = " << resu << endl;
    cout << "hello" << endl;
    return 0;
}