#ifndef STLCOMMON_H
#define STLCOMMON_H

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

using namespace std;

#define SPACE 3
template<typename T1>
void MyPrintTwo(vector<vector<T1>> &data)
{
    cout << "------- start ---------" << endl;
    int col = data[0].size();
    printf("%-4d", 0);
    for(int i = 0; i< col; i++){
        printf("%-12d", i);
    }
    printf("\n");
    cout << "------------------------" << endl;

    for(int i = 0; i< data.size(); i++){
        printf("%-3d|", i);
        for(int j = 0; j < data[i].size(); j++){
            printf("%-12d", data[i][j]);
        }
        printf("\n");
    }
    cout << "------- end ---------" << endl;
}
template<typename T2>
void MyPrintOne(vector<T2> &data)
{
    cout << "------- start ---------" << endl;
    for(int i = 0; i< data.size(); i++){
        printf("%-5d", i);
    }
    printf("\n");
    cout << "------------------" << endl;

    for(int i = 0; i< data.size(); i++){
        printf("%-5d", data[i]);
    }
    printf("\n");
    cout << "------- end ---------" << endl;
}

void RemoveVecEle(vector<int>&nums,int tar)
{
    for(int i= 0; i< nums.size(); i++){
        if(nums[i] == tar){
            nums.erase(nums.begin() + i);
            i--; // 由於容器size-1, 还按照原先的i 的话，相当于自动右一位而漏掉一个元素
        }
    }

}

// 并查集
class UnionFind {
public:
    UnionFind(int n)
    {
        NODENUM = n;
        father.resize(NODENUM,0);
        fa_init();
        


    }
    void fa_init()
    {
        for(int i = 0; i<NODENUM; i++){
            father[i] = i;
        }

    }
    int find_fa(int i)
    {
        // if( i == fa[i]){
        //     return i;
        // }else{
        //     fa[i] = find_fa(fa[i]);
        //     return fa[i];
        // }
        if(father[i] != i){
            father[i] = find_fa(father[i]);
        }
        return father[i];
    }
    void unionNode(int x, int y)
    {
        int i_fa= find_fa(x);
        int j_fa = find_fa(y);
        father[i_fa] = j_fa;
    }
    void PrintFather()
    {
        for(int i = 0 ; i< NODENUM; i++){
            printf("i=%-3d | father=%-3d \n", i, father[i]);
        }
    }

public:
    int NODENUM ; // 总的节点个数
    vector<int>father;// 存储每个节点的父节点
};




class SolutionCalPrimTree{
public:
    vector<vector<int>> CalPrimTree(vector<vector<int>>&figureData)
    {
        vector<vector<int>>treeVec;
        set<int>treeSet;
        vector<bool>isVisited(N,false);
         cout << "22 size= " << treeSet.size() << " N= " << N << endl;
        treeSet.insert(0); // 从任意一个顶点开始，将与其他顶点代价最小的 加入到里面
        isVisited[0] = true;

        while(treeSet.size() != N){ // 直到所有的顶点都有加入
            // cout << "size= " << treeSet.size() << endl;
            vector<int>node = findMinPath(figureData, isVisited, treeSet);
            // cout << " node.size= " << node.size() << endl;
            int i = node[0];
            int j = node[1];
            cout << "treeSet i= " << i <<  " j = " << j << endl;

            treeSet.insert(j);
            isVisited[j] = true;

            treeVec.push_back({i, j});
        }
        cout << "end" << endl;
        return treeVec;
    }
private:
    // 输出下一个加入集合的下一个节点
    vector<int> findMinPath(vector<vector<int>>&figureData, vector<bool>&isVisited, set<int>&treeSet)
    {
        int distance = INT32_MAX;
        int node_i = 0;
        int node_j = 0;
        // cout  << " figureData.size= " << figureData.size() << " " << figureData[0].size() << endl;
        auto it = treeSet.begin();
        while(it != treeSet.end()){
            int start_node =  *it;
            for(int j= 0 ; j< N; j++){
                // cout << "i= " << i << " j= " << j << " N =" << N << " dis= " << figureData[i][j] << endl;
                if(figureData[start_node][j] == 0) continue;
                if(isVisited[j] && isVisited[start_node]) continue;
                if(figureData[start_node][j] < distance){
                    distance = figureData[start_node][j];
                    node_i = start_node;
                    node_j = j;  
                }
            }

            it++;
        }
        // 下一个要加入的节点为 node_j
        cout << "node " << node_i << " " << node_j << endl;
        return {node_i, node_j};
    }


    void MyPrintTwo(vector<vector<int>> &data)
    {
        cout << "------- start ---------" << endl;
        int col = data[0].size();
        printf("%-4d", 0);
        for(int i = 0; i< col; i++){
            printf("%-3d", i);
        }
        printf("\n");
        cout << "------------------------" << endl;

        for(int i = 0; i< data.size(); i++){
            printf("%-3d|", i);
            for(int j = 0; j < data[i].size(); j++){
                printf("%-3d", data[i][j]);
            }
            printf("\n");
        }
        cout << "------- end ---------" << endl;
    }
private:
    vector<vector<int>>figureData; // 邻接矩阵
    int N ;
};





#endif