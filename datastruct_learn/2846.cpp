#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;


// 邻接矩阵

class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges,
                                     vector<vector<int>>& queries) {
        g_figureData.resize(N,vector<int>(N,0));
        g_visited.resize(N,0);
        g_zero.resize(N,0);
        MakeFigureData(edges);

        // MyPrintTwo(g_figureData);
        // return {};
        int begin_num = 0;
        int end_num = 0;
        vector<int> resu;
        for (int i = 0; i < queries.size(); i++) {
            resu.clear();
            // g_visited = g_zero;
            g_visited.clear();
            g_visited.resize(N,0);

            // MyPrintOne(g_visited);
            begin_num = queries[i][0];
            end_num = queries[i][1];
            // cout << " begin_num=  " << begin_num << " end_num= " << end_num
            // << endl;
            resu.push_back(begin_num);
            // cout << " resu.push_back=  " << begin_num  << endl;
            g_visited[begin_num] = 1;
            // cout << " begin_num=  " << begin_num << " end_num= " << end_num << endl;
            DfsFindOnePath(n, begin_num, begin_num, end_num, resu);
        }
        vector<int> queries_ope;
        vector<int> pathWeight;

        for (int i = 0; i < queries.size(); i++) {
            pathWeight.clear();
            // MyPrintOne(outPut[i]);
            for (int j = 0; j < outPut[i].size() - 1; j++) {
                pathWeight.push_back(
                    g_figureData[outPut[i][j]][outPut[i][j + 1]]);
            }
            int times = operator_times(pathWeight);
            queries_ope.push_back(times);
        }

        MyPrintOne(queries_ope);

        return queries_ope;
    }
    int operator_times(vector<int>& nums) {
        int maxTimes = 0;
        // cout << "num ----s" <<endl;
        // MyPrintOne(nums);
        // cout << "num ----s" <<endl;
        unordered_map<int, int> unMap;
        for (int i = 0; i < nums.size(); i++) {
            unMap[nums[i]]++;
            if (unMap[nums[i]] > maxTimes) {
                maxTimes = unMap[nums[i]];
            }
        }
        return nums.size() - maxTimes;
    }
    void DfsFindOnePath(const int n, int cur_num, const int begin_num,
                        const int end_num, vector<int>& resu) {
        // cout << " DfsFindOnePath cur_num " << cur_num  << " begin_num= " <<
        // begin_num << " end_num "<<  end_num << endl;
        if (cur_num == end_num) {
            // MyPrintOne(resu);
            outPut.push_back(resu);
            return;
        }
        // cout << " n=  " << n << endl;
        for (int i = 0; i < n; i++) {
            // printf("g_figureData[%d][%d]=%d \n",cur_num, i,
            // g_figureData[cur_num][i]); printf("g_visited[%d]=%d \n", i,
            // g_visited[i]);
            if (g_figureData[cur_num][i] == 0)
                continue;
            if (g_visited[i] == 1)
                continue;
            g_visited[i] = 1;
            resu.push_back(i);
            DfsFindOnePath(n, i, begin_num, end_num, resu);
            // 回溯
            g_visited[i] = 0;
            resu.pop_back();
        }
    }
    void MakeFigureData(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to_num = edges[i][1];
            int weight = edges[i][2];
            g_figureData[from][to_num] = weight;
            g_figureData[to_num][from] = weight;
        }
    }

private:
    vector<vector<int>> outPut;
    // vector<vector<int>> g_figureData;;
    // vector<int> g_visited;
    // vector<int> g_zero;
    // const vector<int> g_zero(N, 0);
    vector<vector<int>> g_figureData;
    vector<int> g_visited;
    vector<int> g_zero;
    int N =1000;
};

int main()
{
    Solution s1;
    int n = 8;
    vector<vector<int>> edges = {{1,2,6},{1,3,4},{2,4,6},{2,5,3},{3,6,6},{3,0,8},{7,0,2}}; 
    vector<vector<int>> queries  ={{4,6},{0,4},{6,5},{7,4}};
    // vector<vector<int>> edges = {{0,1,1},{1,2,1},{2,3,1},{3,4,2},{4,5,2},{5,6,2}}; 
    // vector<vector<int>> queries  ={{0,3},{3,6},{2,6},{0,6}};

    s1.minOperationsQueries(n, edges, queries);
    cout << "hell22o" << endl;
    return 0;
}