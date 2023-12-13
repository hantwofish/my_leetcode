#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         n = heights.size();
         m = heights[0].size();
         allnum = n * m;
        figuredata.resize(allnum, vector<int>(allnum));
        for(int i = 0; i< n; i++){
            for(int j= 0; j < m; j++){
                get4dif(heights, i,j);
            }
        }
        MyPrintTwo(figuredata);

        CalAllDistance(figuredata);

        return minDistance[0][allnum-1];
    }
    void get4dif(vector<vector<int>>& heights, int i, int j)
    {
        pair<int,int>left = make_pair(i, j-1);
        pair<int,int>right = make_pair(i, j+1);
        pair<int,int>front= make_pair(i-1, j);
        pair<int,int>behind = make_pair(i+1, j);
        if(isVaild(left)){
            int cur =  i*m +j;
            int endinde = left.first * m + left.second;
            figuredata[cur][endinde] = abs(heights[i][j] - heights[left.first][left.second]);
        }
        if(isVaild(right)){
            int cur =  i*m +j;
            int endinde = right.first * m + right.second;
            figuredata[cur][endinde] = abs(heights[i][j] - heights[right.first][right.second]);
        }
        if(isVaild(front)){
            int cur =  i*m +j;
            int endinde = front.first * m + front.second;
            figuredata[cur][endinde] = abs(heights[i][j] - heights[front.first][front.second]);
        }        
        if(isVaild(behind)){
            int cur =  i*m +j;
            int endinde = behind.first * m + behind.second;
            figuredata[cur][endinde] = abs(heights[i][j] - heights[behind.first][behind.second]);
        }
    }
    bool isVaild(pair<int,int>pr)
    {
        if( pr.first < 0 || pr.first >= n  ) return false;
        if( pr.second < 0 || pr.second >= m  ) return false;
        return true;
    }
    void CalAllDistance(vector<vector<int>>&figureInfo)
    {
        int nodNum = allnum; // 节点个数
        minDistance = figureInfo; // 计算两个节点之间最小距离
        int startNodeIndex = 0;
        for(int k =startNodeIndex; k < nodNum; k++){
            minDistance[k][k] = 0;
            for(int i = startNodeIndex; i < nodNum; i++){
                for(int j= startNodeIndex; j< nodNum; j++){
                    // 得到每两个点直接的最短路径
                    minDistance[i][j] = max(minDistance[i][j], min(minDistance[i][k],minDistance[k][j]));
                }
            }
        }
        MyPrintTwo(minDistance);
    }
public:
    vector<vector<int>>figuredata;
    int n;
    int m;
    int allnum;
    vector<vector<int>>minDistance;
};




int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    int resu = s1.minimumEffortPath(heights);

    

    cout << "resu" << resu  << endl;
    return 0;
}