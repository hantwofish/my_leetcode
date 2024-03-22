#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<int>>distance(N,vector<int>(M, INVAILD_NUM));
        distance[0][0] =0;

        for(int i =0 ; i< N; i++){
            for(int j =0 ; j< M; j++){
                int pre_i = -1;
                int pre_j = -1;
                // cout << "111 i= "<< i << " j= " << j << " dis= " << distance[i][j] << endl;
                if(i == 0 && j ==0 ) continue;
                // 1. 从左边到 (i, j)
                for(int k = 0; k <= j-1; k++){
                    if(grid[i][k] + k < j){
                        // cout << "i= "<< i << " j= "<< j << " grid[i][k]=  " << grid[i][k] << " k= " << k << endl;
                        continue;
                    }
                    if(distance[i][k] != INVAILD_NUM  && distance[i][k] + 1 < distance[i][j]){
                        pre_i = i;
                        pre_j = k;
                        distance[i][j] = distance[i][k] + 1;
                    }

                }
                // 2. 从上边到 (i,j)
                for(int k=0; k <= i-1; k++){
                    if(grid[k][j] + k < i){
        // cout << "22 i= "<< i << " j= "<< j << " grid[i][k]=  " << grid[i][k] << " k= " << k << endl;

                        continue;
                    }

                    if(distance[k][j] != INVAILD_NUM && distance[k][j] +1 < distance[i][j]){
                        pre_i = k;
                        pre_j = j;
                        distance[i][j] = distance[k][j] +1;
                    }

                }
                printf("(%d,%d)->(%d,%d)= %d\n", pre_i,pre_j, i, j, distance[i][j]);
                if(distance[i][j] ==  INVAILD_NUM){
                    // cout << "retur -1" << endl;
                    // return -1;
                }

            }
        }
        if(distance[N-1][M-1] == INVAILD_NUM){
            return -1;
        }
        
        cout << "resu= " << distance[N-1][M-1] << endl;
        return distance[N-1][M-1] + 1;

    }
private:
    int INVAILD_NUM =  0x7f7f7f7f; // 或者为 INT32_MAX
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    // vector<vector<int>> grid = {{3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0}};

    vector<vector<int>> grid  = {{3,4,2,1},{4,2,1,1},{2,1,1,0},{3,4,1,0}};

    // vector<vector<int>> grid  = {{2,1,0},{1,0,0}};
    // vector<vector<int>> grid  = {{7,0,2,4},{0,2,3,0}};
    s1.minimumVisitedCells(grid);
    cout << "hell22o" << endl;
    return 0;
}