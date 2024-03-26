#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

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

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

int main()
{
    int n = 13;
    vector<vector<int>>edges={{7,2,131570},{9,4,622890},{9,1,812365},{1,3,399349},{10,2,407736},{6,7,880509},{1,4,289656},{8,0,802664},{6,4,826732},{10,3,567982},{5,6,434340},{4,7,833968},{12,1,578047},{8,5,739814},{10,9,648073},{1,6,679167},{3,6,933017},{0,10,399226},{1,11,915959},{0,12,393037},{11,5,811057},{6,2,100832},{5,1,731872},{3,8,741455},{2,9,835397},{7,0,516610},{11,8,680504},{3,11,455056},{1,0,252721}};
    
    Graph s1(n, edges);
    int resu= s1.shortestPath(9,3);
    cout << "resu= " << resu << endl;
    // resu = s1.shortestPath(0,3);
    //  cout << "resu= " << resu << endl;
    s1.addEdge({11,1,873094});
    resu= s1.shortestPath(3,10);
     cout << "resu= " << resu << endl;
    

    cout << "hell22o" << endl;
    return 0;
}