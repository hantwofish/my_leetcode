#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

// 从某个节点访问所有节点, 回溯
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
            
            cout << "i= " << i << endl;
           MyPrintOne(canVisited);

        }

        return -1;
    }

    void DFS(int start, int cur_index, vector<int>&resu, vector<int>&visited)
    {
        canVisited[cur_index] = 1;
        if(cur_index >= N) return;
        if(visited[cur_index]) return;
        // cout << "  cur= " << cur_index << endl;
    
        resu.push_back(cur_index);
        visited[cur_index] = true;

        // MyPrintOne(resu);

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
        while(it != figureMap.end()) {
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



int main()
{
    int n = 6;
    vector<vector<int>>edges = {{0,1},{0,4},{1,2},{1,3},{5,0},{5,4}};
    Solution S1;
    int resu= S1.findChampion(n, edges);
    
    return 0;
}