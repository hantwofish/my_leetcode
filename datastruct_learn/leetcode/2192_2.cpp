#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        init(n, edges);

        for(int i = 0; i < n_size; i++){
            visited.clear();
            visited.resize(n_size, false);
            dfs(i,i);
        }
        MyPrintTwo(out_resu);
        return {};
    }
    // 访问从 start 开始的所有节点
    void dfs(int start, int cur_index)
    {
        if(visited[cur_index]== true){
            return;
        }
        resu[cur_index].push_back(start);
        cout << " start= " << start << " push= " << cur_index << endl;
        if(start != cur_index){
            out_resu[cur_index].push_back(start);
        }


        visited[cur_index] = true;
        
        for(int i = 0; i <  u_map[cur_index].size(); i++){
            dfs(start, u_map[cur_index][i]);
        }
        // visited[cur_index] = false;
    }
private:
    void init(int n , vector<vector<int>>& edges)
    {
        n_size = n;
        for(int i = 0; i< edges.size(); i++){
            int from = edges[i][0];
            int end = edges[i][1];
            u_map[from].push_back(end);
        }
        visited.resize(n_size, false);
        out_resu.resize(n_size);
    }
    // 临接表
private:
    int n_size;
    unordered_map<int,vector<int>>u_map;
    unordered_map<int,vector<int>>resu;
    vector<vector<int>>out_resu;
    vector<bool>visited;

};




int main()
{
    Solution s1;
    // int n = 8;
    // vector<vector<int>> edgeList = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    int n = 5;
    vector<vector<int>>edgeList = {{0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};

   
    s1.getAncestors(n, edgeList);

    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}