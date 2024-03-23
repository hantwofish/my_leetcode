#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        N = n;
        figureData.resize(N, vector<int>(N, IN_VAILD));
        nodeDistance.resize(N, vector<int>(N, IN_VAILD));

        for(auto &eg: edges){
            int from = eg[0];
            int to =   eg[1];
            int weight = eg[2];
            figureData[from][to]= weight;
            figureData[to][from]= weight;
        }
        MyPrintTwo(figureData);
        CalallDistance(figureData);

        int outNode = 0;
        int minTimes = INT32_MAX;
        for(int i= 0; i< N; i++){
            // int maxDistance = 0;
            int times = 0;
            for(int j =0; j< N;j++){
                if(nodeDistance[i][j] == 0) continue;
                if(nodeDistance[i][j] <= distanceThreshold ){
                    times++;
                }

            }
            cout << "i= " << i  << " times= " << times << endl;
            if( times <= minTimes){
                minTimes = times;
                outNode = i;
            }
            
        }

        cout << "outNode= " << outNode << endl;
        return outNode;
    }
    
    void CalallDistance(vector<vector<int>>&figureData)
    {
        nodeDistance = figureData;
        for(int k =0; k < N; k++){
            nodeDistance[k][k] = 0;
            for(int i = 0; i < N; i++){
                for(int j= 0; j< N; j++){
                    // 得到每两个点直接的最短路径
                    nodeDistance[i][j] = min(nodeDistance[i][j], nodeDistance[i][k]+ nodeDistance[k][j]);
                }
            }
        }
        MyPrintTwo(nodeDistance);

    }
private:    
    vector<vector<int>>figureData;
    vector<vector<int>>nodeDistance; // 计算任意两点之间的距离
    int N =0;  
    int IN_VAILD =   INT32_MAX/2;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    int n = 4;
    vector<vector<int>>edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int distanceThreshold = 4;
    s1.findTheCity(n, edges, distanceThreshold);
    
    

    cout << "hell22o" << endl;
    return 0;
}