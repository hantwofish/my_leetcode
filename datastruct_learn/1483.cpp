#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        visited.resize(n, false);
        for(int i = 0; i< parent.size(); i++){
            tree_map[i].push_back(parent[i]);
        }

        print_map(tree_map);
        cout << " ---- " << endl;

        for(int i = 0; i < n; i++){
            visited.clear();
            visited.resize(n,false);
            dfs_search(i, tree_map[i][0]);
        }
        print_map(resu_map);
    }
    
    int getKthAncestor(int node, int k) {
        if(resu_map[node].size() < k) return -1;
        
        return resu_map[node][k-1];
    }
private:
    void dfs_search(int start_index, int cur_index)
    {
        if(cur_index == -1) return;
        if(visited[cur_index])  return;
        visited[cur_index] = true;

        resu_map[start_index].push_back(cur_index);
            cout << start_index <<  "  push " << cur_index << endl;
        vector<int>neigh = tree_map[cur_index];
        for(int i = 0; i < neigh.size();i++ ){
            dfs_search(start_index, neigh[i]);
        }
    }
    void print_map(unordered_map<int, vector<int>>&tree_map)
    {
        auto it = tree_map.begin();
        while(it != tree_map.end()){
            cout << it->first << " -> ";
            for(int i = 0; i< it->second.size(); i++){
                cout << it->second[i] << " ";
            }
            cout << endl;
            it++;
        }
    }
private:
    unordered_map<int, vector<int>>tree_map;
    unordered_map<int, vector<int>>resu_map;
    vector<int>visited;
};

int main()
{
    vector<int>parent = {-1,0,0,1,1,2,2};
    int n = 7;
    TreeAncestor s1(n, parent);
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}