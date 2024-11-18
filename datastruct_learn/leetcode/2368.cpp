#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution2 {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        N =n;
        figure.resize(n, vector<int>(n,0));
        for(int i = 0; i< edges.size(); i++){
            int start = edges[i][0];
            int end = edges[i][1];

            figure[min(start,end)][max(start,end)] = 1;
        }
        MyPrintTwo(figure);

        int outRnage = 0;
        for(int i = 0; i< restricted.size();i++){
            outRnage += dfs(restricted[i]);
            cout << "i= " << restricted[i] << " restricted[i]num =  " << dfs(restricted[i]) << endl;
        }
        cout << "outRnage= " << outRnage << endl;
        return N- outRnage - restricted.size();
    }
    // 定义以 start 为开始可以到达的节点个数
    int dfs(int start)
    {
        int resu = 0;

        for(int i = 0; i< N; i++){
            if(figure[start][i] == 1){
                resu = 1 +  dfs(i);
            }
        }
        return resu;
    }
private:
    int N ;
    vector<vector<int>>figure;
};


class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        N =n;
        isVisted.resize(n, 0);
        is_restricted.resize(n, 0);
        // figure.resize(n, vector<int>(n,0));
        for(int i = 0; i< edges.size(); i++){
            int start = edges[i][0];
            int end = edges[i][1];

            // figure[start][end] = 1;
            // figure[end][start] = 1;

            umap[start].push_back(end);
            umap[end].push_back(start);
        }
        // MyPrintTwo(figure);
        for(int i = 0; i< restricted.size(); i++){
            is_restricted[restricted[i]] = 1;
        }


        isVisted[0] = true;
        vailNodeNum++;

        dfs(0, restricted);
        cout << "vailNodeNum= " << vailNodeNum << endl;
        return vailNodeNum;
    }
    void dfs(int root, vector<int>& restricted)
    {
        // for(int i = 0; i< N; i++){
        //     if(figure[root][i] == 0){
        //         continue;
        //     }
        //     if(isVisted[i]) continue;

        //     if(find(restricted.begin(), restricted.end(), i) != restricted.end()) continue;
            
        //     isVisted[i] = true;
        //     vailNodeNum++;

        //     cout << root << " -> " << i << endl; 
        //     dfs(i, restricted);
        //     // isVisted[i] = false;
        // }
        vector<int>dig = umap[root];
        for(int i  =0 ; i< dig.size();i++){
            int neigh = dig[i];
            if(isVisted[neigh]) continue;

            // if(find(restricted.begin(), restricted.end(), neigh) != restricted.end()) continue;
            if(is_restricted[neigh]) continue;

            isVisted[neigh] = true;
            vailNodeNum++;

            cout << root << " -> " << neigh << endl; 
            dfs(neigh, restricted);
        }

    }
private:
    int N ;
    // vector<vector<int>>figure;
    unordered_map<int, vector<int>>umap;
    vector<bool>isVisted;
    int vailNodeNum = 0;
    vector<int>is_restricted;
};

int main()
{
    Solution s1;
    int n = 7;
    vector<vector<int>>edges = {{0,1},{0,2},{0,5},{0,4},{3,2},{6,5}}; 
    vector<int>restricted = {4,2,1};

    // int n =7;
    // vector<vector<int>>edges = {{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}}; 
    // vector<int>restricted = {4,5};

    int resui = s1.reachableNodes(n,edges,restricted);
    cout << "resu= " << resui << endl;
     
    // n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]  // 4

    cout << "hell22o" << endl;
    return 0;
}