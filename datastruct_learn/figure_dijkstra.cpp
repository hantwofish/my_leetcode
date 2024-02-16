#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

class Solution{
public:
    void dijkstra_algo(vector<vector<int>>&figure, int nodeNum, int source_node)
    {
        figure_data.resize(nodeNum+1, vector<int>(nodeNum+1, INVAILD_VAL));
        dist.resize(nodeNum+1, INVAILD_VAL);
        pre.resize(nodeNum+1, -1);
        // is_set_s.resize(nodeNum+1, false);
        for(int i =0;i < figure.size(); i++){
            int start_node = figure[i][0];
            int end_node = figure[i][1];
            int value = figure[i][2];

            figure_data[start_node][end_node] = value;
        }
        MyPrintTwo(figure_data);

        // 更新 dis 数组
        for(int i = 0; i< nodeNum; i++){
            if(figure_data[source_node][i] != INVAILD_VAL){
                dist[i] = figure_data[source_node][i];
                pre[i] = source_node;
            }
        }

        set_s.insert(source_node);
        for(int i= 0; i < nodeNum; i++){
            if(i == source_node) {
                continue;
            }else {
                set_v_s.insert(i);
            }
            
        }

        while(!set_v_s.empty()){
            // 找到dist中最小的距离
            int min_distance = INVAILD_VAL;
            int k = *set_v_s.begin();
            for(auto it = set_v_s.begin(); it != set_v_s.end(); it++){
                if(dist[*it] < min_distance){
                    min_distance = dist[*it];
                    k = *it;
                }
            }
            cout << "k= " << k << endl;
            set_s.insert(k);
            set_v_s.erase(k);
            // 判断是否结束
            if(set_v_s.empty()) break;;
            // 借东风，更新v-s 集合中  dist距离
            for(auto it = set_v_s.begin(); it != set_v_s.end(); it++){
                int j = *it;
                if(dist[k] + figure_data[k][j] < dist[j]){
                    dist[j] = dist[k] + figure_data[k][j];
                    pre[j] = k;
                    cout << "k= " << k << " j= " << j << " " << dist[k]  << " " << figure_data[k][j] << endl;
                }
            }
        }
        MyPrintOne(dist);
        MyPrintOne(pre);


    }
private:
    vector<vector<int>>figure_data; // 邻接矩阵
    vector<int>dist;
    vector<int>pre;
    // vector<bool>is_set_s;
    set<int>set_s;
    set<int>set_v_s;
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
    s1.dijkstra_algo(nums, N, 0);
    cout<< "hello" << endl;
    return 0;
}