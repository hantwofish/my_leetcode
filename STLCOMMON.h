#ifndef STLCOMMON_H
#define STLCOMMON_H

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
template<typename T1>
void MyPrintTwo(vector<vector<T1>> &data)
{
    for(int i = 0; i< data.size(); i++){
        for(int j = 0; j < data[i].size(); j++){
            cout<< data[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}
template<typename T2>
void MyPrintOne(vector<T2> &data)
{
    for(int i = 0; i< data.size(); i++){
        cout<< data[i] << " ";
    }
    cout << endl;
}


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
#endif