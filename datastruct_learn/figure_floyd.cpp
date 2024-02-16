#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

class Solution{
public:
   void Floyd(vector<vector<int>>figure, int nodeNum)
   {
        figure_data.resize(nodeNum+1, vector<int>(nodeNum+1, INVAILD_VAL));
        dist.resize(nodeNum+1, vector<int>(nodeNum+1, INVAILD_VAL));
        prev.resize(nodeNum+1, vector<int>(nodeNum+1, -1));
        // is_set_s.resize(nodeNum+1, false);
        for(int i =0;i < figure.size(); i++){
            int start_node = figure[i][0];
            int end_node = figure[i][1];
            int value = figure[i][2];

            figure_data[start_node][end_node] = value;
            dist[start_node][end_node] = value;
            prev[start_node][end_node] = start_node;
        }
        // 插入点，更新dist prev
        for(int start_node =0; start_node < nodeNum; start_node++){
            for(int end_node = 0; end_node < nodeNum; end_node++){
                for(int insert_node = 0; insert_node < nodeNum; insert_node++){
                    if(dist[start_node][insert_node] + dist[insert_node][end_node] < dist[start_node][end_node]){
                        dist[start_node][end_node] = dist[start_node][insert_node] + dist[insert_node][end_node];
                        prev[start_node][end_node]  = prev[insert_node][end_node];
                    }
                }

            }
        }
        MyPrintTwo(dist);
        MyPrintTwo(prev);

   }
private:
    vector<vector<int>>figure_data; // 邻接矩阵
    vector<vector<int>>dist;
    vector<vector<int>>prev;

    int32_t INVAILD_VAL = 100;
};

int main()
{
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
    Solution s1;
    s1.Floyd(nums, N);
    cout<< "hello" << endl;
    return 0;
}