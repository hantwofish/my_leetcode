#include"../../STLCOMMON.h"
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int M =grid.size();
        int N =grid[0].size();
        fa.resize(M*N,-1);
        unionInit(grid);
        MyPrintOne(fa);

         
        // 循环遍历,只要是相邻的就合并
        for(int i = 0; i < M;i++){
            for(int j = 0; j< N;j++){
                if(grid[i][j] == '0'){
                    continue;
                }
                int index = i *N +j;
                // 判断四个方向，有联通的，进行合并，位置置为0
                for(int direcIndex= 0; direcIndex < 4; direcIndex++){
                    int xloc = i + direct[direcIndex][0];
                    int yloc = j + direct[direcIndex][1];
                    // 索引范围
                    if(xloc >= 0 && xloc < M &&  yloc >= 0 && yloc < N){
                        if(grid[xloc][yloc] == '1'){
                            int indiex2 = xloc * N + yloc;
                            Union(indiex2, index);
                            //cout << "fa["<< indiex2<< "]= " << fa[indiex2] <<endl;
                        }
                    }
                }

            }
        }

        MyPrintOne(fa);
        unordered_set<int> resu;
        for(int i = 0; i< fa.size(); i++){
            if(fa[i] != -1){
                resu.insert(fa[i]);
            }
        }




       return resu.size(); 
    }
    void unionInit(vector<vector<char>>& grid)
    {
        int M =grid.size();
        int N = grid[0].size();
        for(int i = 0; i< M; i++){
            for(int j =0 ;j <N;j++){
                int index = i*N+j;
                // cout << "index= " << index << " " << i << " " << j << endl;
                if(grid[i][j] != '1'){
                    continue;
                }
                
                fa[index] = index;
            }
        }
    }
    int findFa(int i )
    {
        if(fa[i] != i){
            fa[i] = findFa(fa[i]);
        }
        return fa[i];
    }
    // 把 i 合并到 j
    void Union(int i ,int j)
    {
        int i_fa= findFa(i);
        int j_fa = findFa(j);
        fa[i_fa] = j_fa;
    }
public:
    vector<int>fa;
    int direct[4][2] = {{0,0},{0,-1},{-1,0},{0,0}};   
};


int main()
{
    Solution s1;
    vector<vector<char>>grid = {
        {'1','0','1','1','1'},
        {'1','0','1','0','1'},
        {'1','1','1','0','1'}
    };
    int resu =s1.numIslands(grid);
    cout << "resu = " << resu << endl;
    return 0;
}