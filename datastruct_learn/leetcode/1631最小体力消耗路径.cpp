#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        N = heights.size();
        M = heights[0].size();
        isVisited.resize(N,vector<int>(M,0));
        DFSbacktraing(heights,0,0,0,0);
        // cout << "resu.size= " << allPath.size() << endl;
        // MyPrintTwo(allPath);

        return outputresu;
    }   

    bool indeXIsVaild(int i, int j)
    {
        if(i <0 || i>= N) {
            return false;
        }
        if(j < 0 || j >= M){
            return false;
        }
        return true;
    }
    void DFSbacktraing(vector<vector<int>>& heights, int start_i, int start_j, int cur_i, int cur_j)
    {
        if(isVisited[cur_i][cur_j]){
            return;
        }
        if(cur_i == N -1 && cur_j == M-1){
            onePath.push_back(heights[cur_i][cur_j]);
            allPath.push_back(onePath);
            
            MyPrintOne(onePath);
            int temp = 0;
            for(int j= 1;j < onePath.size(); j++){
                
                temp = max(temp, abs(onePath[j] - onePath[j-1]));
            }
            cout << "temp = " << temp << endl;
            outputresu = min(outputresu, temp);

            onePath.pop_back();
            return;
        }
        if(onePath.size() > 2 && (abs(onePath[onePath.size()-1] - onePath[onePath.size()-2]) > outputresu)){
            return;
        }


        // 可以上下左右移动
        
        isVisited[cur_i][cur_j ] = true;
        onePath.push_back(heights[cur_i][cur_j]);
        // 上 下左右
        if(indeXIsVaild(cur_i - 1 ,cur_j) ) DFSbacktraing(heights, start_i, start_j, cur_i - 1, cur_j);
        if(indeXIsVaild(cur_i + 1 ,cur_j) ) DFSbacktraing(heights, start_i, start_j, cur_i + 1, cur_j);
        if(indeXIsVaild(cur_i ,cur_j - 1) ) DFSbacktraing(heights, start_i, start_j, cur_i, cur_j -1);
        if(indeXIsVaild(cur_i ,cur_j + 1) ) DFSbacktraing(heights, start_i, start_j, cur_i, cur_j + 1);

        isVisited[cur_i][cur_j ] = false;
        onePath.pop_back();
    }
public:
    int N = 0;
    int M = 0;
    vector<vector<int>>allPath;// 记录一条路径上最大值最小值
    vector<int>onePath;
    vector<vector<int>>isVisited;
    int outputresu = INT32_MAX;
};




int main()
{
    Solution s1;
    vector<vector<int>>heights = {{10,8},{10,8},{1,2},{10,3},{1,3},{6,3},{5,2}};
    int resu = s1.minimumEffortPath(heights);

    

    cout << "resu= " << resu << endl;
    return 0;
}