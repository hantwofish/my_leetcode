#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution2 {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        N = n;
        for(int i = 0; i< edges.size(); i++){
            figureMap[edges[i][0]].push_back(edges[i][1]);
        }
        // PrintMap();
        for(int i = 0 ; i< N; i++){
            canVisited.clear();
            canVisited.resize(N,0);
            DFS(i,i);

           if(isAllFind(canVisited)){
                return i;
           }

        }

        return -1;
    }
    bool isAllFind(vector<int>&canVisited)
    {

        int i = 0;
        while(i < canVisited.size()) {
            if(canVisited[i] == 0){
                return false;
            }
            i++;
        }
        return true;
    }
    void DFS(int start, int cur_index)
    {
        canVisited[cur_index] = 1;
        if(cur_index >= N) return;
        // if(visited[cur_index]) return;
        // cout << "  cur= " << cur_index << endl;
    
        // resu.push_back(cur_index);
        // visited[cur_index] = true;

        // MyPrintOne(resu);

        // vector<int>neigh = figureMap[cur_index];
        for(int i = 0; i < figureMap[cur_index].size(); i++){

            DFS(start, figureMap[cur_index][i]);

        }
        // resu.pop_back();
        // visited[cur_index] = false;

    }
    void PrintMap()
    {
        auto it = figureMap.begin();
        while(it != figureMap.end()){
            cout << it->first << " | ";
            for(auto i : it->second){
                cout << i << " ";
            }
            cout << endl;
            it++;
        }
    }
private:
    unordered_map<int,vector<int>>figureMap;
    int N;
    vector<int>canVisited;
}; 

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        N = n;
        for(int i = 0; i< edges.size(); i++){
            figureMap[edges[i][0]].push_back(edges[i][1]);
        }
        PrintMap();
        for(int i = 0 ; i< N; i++){
            vector<int>resu;
            vector<int>visited(N, 0);
            canVisited.clear();
            canVisited.resize(N,0);
            DFS(i,i, resu, visited);

           if(isAllFind(canVisited)){
                return i;
           }

        }

        return -1;
    }
    bool isAllFind(vector<int>&canVisited)
    {

        int i = 0;
        while(i < canVisited.size()) {
            if(canVisited[i] == 0){
                return false;
            }
            i++;
        }
        return true;
    }
    void DFS(int start, int cur_index, vector<int>&resu, vector<int>&visited)
    {
        canVisited[cur_index] = 1;
        if(cur_index >= N) return;
        if(visited[cur_index]) return;
        cout << "  cur= " << cur_index << endl;
    
        resu.push_back(cur_index);
        visited[cur_index] = true;

        MyPrintOne(resu);

        vector<int>neigh = figureMap[cur_index];
        for(int i = 0; i < neigh.size(); i++){

            DFS(start, neigh[i], resu,visited);

        }
        resu.pop_back();
        visited[cur_index] = false;

    }
    void PrintMap()
    {
        auto it = figureMap.begin();
        while(it != figureMap.end()){
            cout << it->first << " | ";
            for(auto i : it->second){
                cout << i << " ";
            }
            cout << endl;
            it++;
        }
    }
private:
    unordered_map<int,vector<int>>figureMap;
    int N;
    vector<int>canVisited;
}; 


// 计算入度 ,只有一个 入度为 0 的节点
class Solution3 {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        N = n;
        for(int i = 0; i < N; i++){
            indig[i] = 0;
        }
        for(int i = 0; i< edges.size(); i++){
            figureMap[edges[i][0]].push_back(edges[i][1]);
            indig[edges[i][1]]++;
        }

        int zeroindig_num = 0;
        int zero_indig_index  = -1;
        auto it = indig.begin();
        while(it != indig.end()){
            if(it->second == 0){
                zero_indig_index =  it->first;
            }
            it++;
        }
        if(zeroindig_num != 1){
            return -1;
        }
        return zero_indig_index;
    }
private:
    unordered_map<int,vector<int>>figureMap;
    int N;
    vector<int>canVisited;
    unordered_map<int,int>indig;
};
int main()
{
    int n = 4;
    vector<vector<int>>edges = {{0,2},{1,2},{1,3}};
    Solution S1;
    int resu= S1.findChampion(n, edges);
    
    cout << "resu= " << resu  << endl;
    return 0;
}