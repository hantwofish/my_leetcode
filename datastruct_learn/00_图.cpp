#include"../STLCOMMON.h"
#include"../COMMONALO.h"


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


class DiskstraSAlgo{
public:
    void claAxDistacnce(int start_index, vector<vector<int>>&nums, int n) // u为源点
    {
        init(nums,n);

        for(int i = 0 ; i< n;i++){
            distance_arr[i] = figureData[start_index][i];
            flag_arr[i] =  false;
            if(distance_arr[i] == MAXVALUE){
                prenode[i] = -1;
            }else {
                prenode[i] = start_index;
            }
        }
        distance_arr[start_index] = 0;
        flag_arr[start_index] = true; // 加入s 集合




        for(int i = 1; i< n; i++){ // 一共需要遍历次数，

            // 从 v-s 集合中找 dis 中最小的值,以及节点 t
            int tempvalue = MAXVALUE;
            int tempindex = start_index;
            for(int j = 0; j < n ;j++){
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
            for(int j = 0; j < n ; j++){
                // if(figureData[tempindex][j] == MAXVALUE) continue;
                if( !flag_arr[j] && distance_arr[tempindex] + figureData[tempindex][j] < distance_arr[j]){
                    distance_arr[j] = distance_arr[tempindex] + figureData[tempindex][j];
                    prenode[j] = tempindex;
                }
            }
        }
        MyPrintOne(distance_arr);
        MyPrintOne(prenode);
        

    }
    void init(vector<vector<int>>&nums,int n)
    {
        distance_arr.resize(n, 0);
        flag_arr.resize(n,false);
        prenode.resize(n, -1);
        


        figureData.resize(n,vector<int>(n,MAXVALUE));
        for(int i = 0; i < nums.size(); i++){
            
            int frontnumber = nums[i][0];
            int tonumber = nums[i][1];
            int value = nums[i][2];
            figureData[frontnumber][tonumber] =  value;       
        }

    }

public:
    vector<vector<int>>figureData;
    int nodeNum = 0;
    int MAXVALUE = 0x3f3f3f3f;
    vector<int>distance_arr;
    vector<bool>flag_arr;
    vector<int>prenode;

};
int main()
{
    DiskstraSAlgo s1;
    int N = 5;
    vector<vector<int>>nums ={
        {0,1,1},
        {0,2,1},
        {0,3,3},
        {0,4,6},
        {1,3,1},
        {2,3,7},
        {3,4,1}

    };
    s1.claAxDistacnce(0,nums, N);
    // MyPrintOne(nums[0]);
    cout << "heoo" << endl;

    return 0;
}