#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        N = points.size();
        if(N <= 1) return 0;
        figureData.resize(N, vector<int>(N,0));
        
        cout << "N= " << N << endl;

        for(int i =0; i< N; i++){
            for(int j = i + 1; j < N;j++){
                int front_i = points[i][0];
                int frony_j = points[i][1];
                int behind_i = points[j][0];
                int behind_j = points[j][1];

                int distance = abs(front_i - behind_i) + abs(frony_j - behind_j);
                figureData[i][j]  = distance;
                figureData[j][i] =  distance;
            }
        }
        MyPrintTwo(figureData);
        vector<vector<int>> treVec = CalPrimTree(figureData);
        MyPrintTwo(treVec);
        int mincost = 0;
        for(int i = 0; i< treVec.size(); i++){
            mincost +=  figureData[treVec[i][0]][treVec[i][1]];
        }
        cout << "mincost " << mincost << endl;
        return mincost;

    }
private:
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

private:
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
    vector<vector<int>>figureData; // 邻接矩阵
    int N ;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    // vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    // vector<vector<int>> points = {{2,-3},{-17,-8},{13,8},{-17,-15}};
    vector<vector<int>> points = {{0,0},{1,1},{1,0},{-1,1}};
    s1.minCostConnectPoints(points);
    

    cout << "hell22o" << endl;
    return 0;
}