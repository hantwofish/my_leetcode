#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include<map>

using namespace std;
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        figureData.resize(N, 0);
        for(int i = 0; i< roads.size();i++){
            int begin = roads[i][0];
            int end = roads[i][1];
            figureData[begin][end] = figureData[end][begin] = 1;
        }
        
        return resu;
    }
    void DFSCalSubNodeNum(int start, int& subNum)
    {


    }
public:
    int resu  =0;
    int N  = 100;
    vector<vector<int>>figureData;
};
class Solution2 {
public:
    // 当前节点以及自己节点个数的总和
    long long DFS(vector<vector<int>> &vertex, long long &cnt, int visited[], int &seats, int curr) {
        if (visited[curr]) return 0;
        long long person = 1;
        visited[curr] = 1;
        for (auto ver: vertex[curr]) {
            person += DFS(vertex, cnt, visited, seats, ver);
        }
        cnt += (person + seats - 1) / seats; // ⌈person/seats⌉ 向上取整
        return person;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long cnt = 0;
        int visited[roads.size()+1];
        vector<vector<int>> vertex(roads.size()+1);
        memset(visited, 0, sizeof(visited));
        for (auto road: roads) {
            vertex[road[0]].push_back(road[1]);
            vertex[road[1]].push_back(road[0]);
        }
        DFS(vertex, cnt, visited, seats, 0);
        cnt -= (roads.size() + 1 + seats - 1) / seats; // [节点总个数 / seats]
        return cnt;
    }
};

// 作者：YRoads
// 链接：https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main()
{
    Solution s1;
    s1.
    

    vector<vector<int>> roads = {{3,1},{3,2},{1,0},{0,4},{0,5},{4,6}};
    int seats = 2;
    long long resu =s1.minimumFuelCost(roads,seats);
    cout << "resu2 = " << resu << endl;
    return 0;
}