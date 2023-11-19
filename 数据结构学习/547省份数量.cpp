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

class UnionFind2 {
public:
    UnionFind2(int n)
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

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        UnionFind2 u1(N);
        for(int i =0; i < N; i++){
            for(int j = 0; j< N; j++){
                if(isConnected[i][j] == 1){
                    u1.unionNode(i,j);
                }

            }
        }
        u1.PrintFather();
        set<int>mySet;
        for(int i = 0 ; i< u1.NODENUM; i++){
            // printf("i=%-3d | father=%-3d \n", i, u1.find_fa(i));
            mySet.insert(u1.find_fa(i));
        }

        return mySet.size();
    }
};



int main()
{
    Solution s1;
    vector<vector<int>>isConnected = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    int resu = s1.findCircleNum(isConnected);
    cout << "resu= " << resu << endl;

    

    cout << "hello" << endl;
    return 0;
}