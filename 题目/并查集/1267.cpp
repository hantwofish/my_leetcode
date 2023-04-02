#include"../STLCOMMON.h"
using namespace std;
#define MAXNUM 100

struct hash_pair{
    template<class T1, class T2>
    size_t operator()(const pair<T1,T2>&p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T1>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution2 {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        return 0;
    }
    void fa_init(int n)
    {
        for(int i = 1; i<= n; i++){
            fa[i] = i;
        }

    }
    int find_fa(int i)
    {
        // if( i == fa[i]){
        //     return i;
        // }else{
        //     fa[i] = find_fa(fa[i]);
        //     return fa[i];
        // }
        if(fa[i] != i){
            fa[i] = find_fa(fa[i]);
        }
        return fa[i];
    }
    void Union(int i ,int j)
    {
        int i_fa= find_fa(i);
        int j_fa = find_fa(j);
        fa[i_fa] = j_fa;
    }
    int fa[MAXNUM];
};
unordered_map<pair<int,int>, pair<int ,int>,hash_pair> fatMap_1;
unordered_map<pair<int,int>, int, hash_pair> fatMap_2;
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        rowCount.resize(N,0);
        colCount.resize(N,0);
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] != 1){
                    continue;
                }
                rowCount[i]++;
                colCount[j]++;
            }
        }
        // MyPrintOne(rowCount);
        // MyPrintOne(colCount);
        // 遍历
        int resu = 0;
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] != 1){
                    continue;
                }
                if(rowCount[i] > 1 || colCount[j] >1){
                    // cout <<"i= " << i << "j= " << j << endl;
                    resu++;
                }

            }
        }
        return resu;
    }
public:
// 记录每行和每列服务器数量
    // int rowCount[251] = {0};
    // int colCount[251] = {0};
    vector<int>rowCount;
    vector<int>colCount;
    int N =5;
};

int main()
{
    Solution s1;
    vector<vector<int>>grid = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    int resu = s1.countServers(grid);
    cout << "resu= " << resu << endl;

    return 0;
}