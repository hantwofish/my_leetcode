#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
       init(n, edges); 
       CalallDistance(figure_data);
       vector<vector<int>>resu(nsize);
       for(int i = 0; i < nsize; i++){
            for(int j = 0; j < nsize; j++){
                if(i==j) continue;
                if(figure_data[i][j] != INVAILD_NUM){
                    resu[j].push_back(i);
                }

            }
       }
       MyPrintTwo(resu);
       return resu;
    }
private:
    void CalallDistance(vector<vector<int>>&figureData)
    {
        int N = nsize;
        // nodeDistance = figureData;
        for(int k =0; k < N; k++){
            figureData[k][k] = 0;
            for(int i = 0; i < N; i++){
                for(int j= 0; j< N; j++){
                    // 得到每两个点直接的最短路径
                    if(figureData[i][k] != INVAILD_NUM && figureData[k][j] != INVAILD_NUM)  {
                        figureData[i][j] = min(figureData[i][j], figureData[i][k]+ figureData[k][j]);
                    }
                    
                }
            }
        }
        // MyPrintTwo(nodeDistance);

    }
    void init(int n, vector<vector<int>>&edges)
    {
        nsize = n;
        figure_data.resize(nsize, vector<int>(nsize, INVAILD_NUM));
        for(int i = 0; i < edges.size(); i++){
            int from = edges[i][0];
            int end = edges[i][1];
            // int val = edges[i][2];
            int val = 1;
            figure_data[from][end] = val;
        }
        MyPrintTwo(figure_data);

    }
private:
    int nsize;
    vector<vector<int>>figure_data;
    vector<vector<int>>nodeDistance;
    int INVAILD_NUM = INT32_MAX;
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