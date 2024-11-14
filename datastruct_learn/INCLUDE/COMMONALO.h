#ifndef COMMON_ALO
#define COMMON_ALO

#include"./STLCOMMON.h"

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
// 此只要我们向左👈找到第一个比A[i]小的数A[left]以及向右👉找到第一个比E小的数A[right]，就可以确定E的辐射范围为A[left+1:right]。这就叫做下一个更小/更大的数问题。解决这类问题的通用解法即为单调栈。

// 作者：超小白
// 链接：https://leetcode.cn/problems/sum-of-subarray-minimums/submissions/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class sigStack{
public:
    void calNeiMin(vector<int>&nums){
        int N =nums.size();
        leftArry.resize(N,-1);
        rightArry.resize(N,N);
        // 计算右面第一个小于当前元素的位置，记录索引
        stack<int>rightStak;
        for(int i = 0; i <N; i++){
            if(rightStak.empty()) {
                rightStak.push(i);
                continue;
            }
            int tempval = nums[i];
            // cout << "top= " << nums[rightStak.top()] << " tempvla= " << tempval << endl;
            while((!rightStak.empty()) &&  (tempval < nums[rightStak.top()])){
                
                rightArry[rightStak.top()] = i;
                rightStak.pop();
            }
            rightStak.push(i);
        }
        MyPrintOne(rightArry);

        // 计算左面第一个小于的位置
        stack<int>leftstack;
        for(int i = N-1; i >= 0; i--){
            if(leftstack.empty()) {
                leftstack.push(i);
                continue;
            }
            int tempval = nums[i];
            // cout << "top= " << nums[leftstack.top()] << " tempvla= " << tempval << endl;
            while((!leftstack.empty()) &&  (tempval < nums[leftstack.top()])){
                
                leftArry[leftstack.top()] = i;
                leftstack.pop();
            }
            leftstack.push(i);
        }
        MyPrintOne(leftArry);
        

    }


public:
    vector<int>leftArry;
    vector<int>rightArry;

};

// 进制转换
class bitTrans {
public:
    string int_to_bin(int num)
    {
        string resu = "";
        int temp_num = num;
        while(num > 0){
            resu =  to_string(num % 2) + resu;
            num = num /2;
        }
        cout<< "num= " << temp_num << " " << resu << endl;
        return resu;
    }
};


class FigureSearch{
private:
   // 访问从 start 开始的所有节点, 不回溯
    void dfs_nobackup(int start, int cur_index, vector<int>&isVisited)
    {
        if(isVisited[cur_index]== true){
            return;
        }

        cout << " start= " << start << " push= " << cur_index << endl;
        if(start != cur_index){
            // out_resu[cur_index].push_back(start); 此时 start 可以访问到 cur_index
        }


        isVisited[cur_index] = true;
        
        for(int i = 0; i <  figureMap[cur_index].size(); i++){
            dfs_nobackup(start, figureMap[cur_index][i] , isVisited);
        }
    }
    void DFS(int start_node , int end_node, int cur_node, vector<int>&isVisited, vector<int>&onePath)
    {
        if(isVisited[cur_node] == true){
            return;
        }
        if(cur_node == end_node){
            onePath.push_back(cur_node);
            MyPrintOne(onePath);
            onePath.pop_back();
            return;
        }
        onePath.push_back(cur_node);
        isVisited[cur_node] = true;
        vector<int>neighbored = figureMap[cur_node];
        for(int i = 0; i < neighbored.size(); i++){
            DFS(start_node, end_node, neighbored[i], isVisited, onePath);
        }

        onePath.pop_back();
        isVisited[cur_node] = false;
    }   
private:
    void PrintMap(unordered_map<int,vector<int>>figureMap)
    {
        auto it = figureMap.begin();
        while(it != figureMap.end()){
            vector<int>temp = it->second;
            cout << it->first << " | ";
            for(auto &val : temp){
                cout << val << " " ;
            }
            cout << endl;
            it++;
        }
    }

private:
    unordered_map<int, vector<int>>figureMap;
};


class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        figureData.resize(N, vector<int>(N, INVAILD_NUM));
        for(int i= 0; i< edges.size(); i++){
            // figureData[i][i] = 0;

            int from_node = edges[i][0];
            int end_node = edges[i][1];
            int val_node = edges[i][2];
            figureData[from_node][end_node] = val_node;
        }
        // MyPrintTwo(figureData);

    }
    
    void addEdge(vector<int> edge) {
        int from_node = edge[0];
        int end_node = edge[1];
        int val_node = edge[2];
        figureData[from_node][end_node] = val_node;
    }
    
    int shortestPath(int node1, int node2) {
        /* 单源计算 */
        // vector<int>distance_arr; 
        // vector<bool>flag_arr;
        // vector<int>prenode;
        // CalSingeNodeDistance(figureData, N, node1, distance_arr, flag_arr, prenode);
        // if(distance_arr[node2] == INVAILD_NUM){
        //     return -1;
        // }
        // return distance_arr[node2];
        CalallDistance(figureData);
        if(nodeDistance[node1][node2] == INVAILD_NUM){
            return -1;
        }
        return nodeDistance[node1][node2];
    }
    // 单源
    void CalSingeNodeDistance(vector<vector<int>>&figureData, int N, int start_index, vector<int>&distance_arr, vector<bool>&flag_arr, vector<int>&prenode)
    {
        distance_arr.clear();
        distance_arr.resize(N, INVAILD_NUM);
        flag_arr.resize(N, false);
        prenode.resize(N, -1);

        for(int i = 0 ; i< N;i++){
            distance_arr[i] = figureData[start_index][i];
            flag_arr[i] =  false;
            if(distance_arr[i] == INVAILD_NUM){
                prenode[i] = -1;
            }else {
                prenode[i] = start_index;
            }
        }
        distance_arr[start_index] = 0;
        flag_arr[start_index] = true; // 加入s 集合

        
        for(int i = 1; i< N; i++){ // 一共需要遍历次数，

            // 从 v-s 集合中找 dis 中最小的值,以及节点 t
            int tempvalue = INVAILD_NUM;
            int tempindex = start_index;
            for(int j = 0; j < N ;j++){
                if(flag_arr[j] == true) continue; // 在 s 集合中

                if(distance_arr[j] < tempvalue){
                    tempvalue = distance_arr[j];
                    tempindex = j;
                }
            }
            if(tempindex == start_index) return; // 没有找到，不联通
            // 将最小的加入的 S集合
            flag_arr[tempindex] = true;
            // 对 s 集合松弛操作
            for(int j = 0; j < N ; j++){
                // if(figureData[tempindex][j] == INVAILD_NUM) continue;
                if( !flag_arr[j] && distance_arr[tempindex] + figureData[tempindex][j] < distance_arr[j]){
                    distance_arr[j] = distance_arr[tempindex] + figureData[tempindex][j];
                    prenode[j] = tempindex;
                }
            }
        }
        // MyPrintOne(distance_arr);
        // MyPrintOne(prenode);

    }

    // 计算所有顶点
    void CalallDistance(vector<vector<int>>&figureData)
    {
        nodeDistance = figureData;
        for(int k =0; k < N; k++){
            nodeDistance[k][k] = 0;
            for(int i = 0; i < N; i++){
                for(int j= 0; j< N; j++){
                    // 得到每两个点直接的最短路径
                    if(nodeDistance[i][k] != INVAILD_NUM && nodeDistance[k][j] != INVAILD_NUM)  {
                        nodeDistance[i][j] = min(nodeDistance[i][j], nodeDistance[i][k]+ nodeDistance[k][j]);
                    }
                    
                }
            }
        }
        // MyPrintTwo(nodeDistance);

    }

private:
    vector<vector<int>>figureData;
    int INVAILD_NUM = INT32_MAX / 2;
    int N = 0;
    vector<vector<int>>nodeDistance;
};

/*
resu= {}
def backtrack(路径， 选择列表)
    if 满足结束条件：
        resu.add(路径)
        return
    for 选择 in 选择列表
        做选择
        backtrack(路径， 选择列表)
        撤销选择
*/
// 子集
class BackT{
public:
    // 输入一个不包含重复数字的数组，求这些数字的所有子集
    vector<vector<int>> subSets(vector<int>&nums)
    {
        for(int cur = 0;  cur < nums.size(); cur++){
            vector<int>temp;
            visited.clear();
            visited.resize(nums.size(), 0);
            subSetBacking(nums, temp, visited, cur, cur);
        }
        PrintVctwo(resu);
        return resu;
    }
    void subSetBacking(vector<int>&nums, vector<int>&temp, vector<int>&visited, int start, int cur)
    {
        
        if(visited[cur]) return;
    
        temp.push_back(nums[cur]);
        resu.push_back(temp);
        visited[cur] = 1;
        for(int i = cur+1; i < nums.size(); i++){
            subSetBacking(nums, temp,visited, start, i);
        }
        visited[cur] = 0;
        temp.pop_back();
    }
    void PrintVctwo(vector<vector<int>>&resu)
    {
        for(int i = 0 ; i < resu.size(); i++){
            for(int j = 0; j < resu[i].size(); j++){
                cout << resu[i][j] << " ";
            }
            cout << endl;
        }
    }
private:
    vector<vector<int>>resu;
    vector<int>visited;


};

// 组合 输入两个数字N,K ，算法输出 [1-N]中k个数字的所有组合
class BackY{

public:
    vector<vector<int>> combine(int n,int k)
    {
        for(int i = 1; i<= n; i++){
            vector<int>temp;
            vector<int>visited(n+1, 0);
            backTraing(n, k , i, i, temp, visited);
        }
        PrintVctwo(resu);
        return resu;
    }
    void backTraing(int N , int k , int start, int cur, vector<int>&temp, vector<int>&visited)
    {
        if(visited[cur]) return;

        temp.push_back(cur);
        if(temp.size() == k){
            resu.push_back(temp);
        }
         
        visited[cur] = true;

        for(int i = cur + 1; i <= N; i++ ){
            backTraing(N, k, start, i, temp, visited);
        }

        temp.pop_back();
        visited[cur] = false;
    }
    void PrintVctwo(vector<vector<int>>&resu)
    {
        for(int i = 0 ; i < resu.size(); i++){
            for(int j = 0; j < resu[i].size(); j++){
                cout << resu[i][j] << " ";
            }
            cout << endl;
        }
    }
private:
    vector<vector<int>>resu;
};

// 全排列

class BackZ{
public:
    vector<vector<int>> permute(vector<int>&nums)
    {
        for(int i = 0; i < nums.size(); i++){
            vector<int>temp;
            vector<int>visited(nums.size(),0);
            backtraing(nums, i, i, temp, visited);
        }

        PrintVctwo(resu);
        return resu;

    }
    void backtraing(vector<int>&nums, int start, int cur_indx, vector<int>&temp, vector<int>&visited)
    {
        if(visited[cur_indx]) return;
        temp.push_back(nums[cur_indx]);
        if(temp.size()== nums.size()){
            resu.push_back(temp);
        }
        visited[cur_indx] = true;

        for(int i = 0; i < nums.size(); i++){
            backtraing(nums, start, i, temp, visited);
        }

        temp.pop_back();
        visited[cur_indx] = false;
    }

private:
    void PrintVctwo(vector<vector<int>>&resu)
    {
        for(int i = 0 ; i < resu.size(); i++){
            for(int j = 0; j < resu[i].size(); j++){
                cout << resu[i][j] << " ";
            }
            cout << endl;
        }
    }
    vector<vector<int>>resu;
};



#endif