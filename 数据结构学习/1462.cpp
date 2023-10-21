#include"../STLCOMMON.h"

using namespace std;

// 构造一个有向图，能从开始到结束则为 先修条件
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        Init(numCourses,prerequisites,queries);
        MakeFigure(prerequisites);
        PrintFigure();
        for(int i = 0 ;i < queries.size(); i++){
            int start = queries[i][0];
            int end= queries[i][1];
            DFS(start, start, end);
        }

        vector<bool>outData;
        for(int i = 0 ;i < queries.size(); i++){
            int start = queries[i][0];
            int end= queries[i][1];
            cout << "start= " << start << " end= " << end << endl;
            auto temp = make_pair(start, end);
            if( find(resu.begin(), resu.end(), temp) != resu.end()){
                outData.push_back(true);
            }else{
                outData.push_back(false);
            }
        }
        
        MyPrintOne(outData);

        return outData;
    }
    void Init(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        Number = numCourses;
        // resu.resize(queries.size(), false);
        isUsed.resize(Number, false);
    }
    void DFS(int start, int cur, int end)
    {
        cout << "DFS start= " << start << " cur= " << cur << "  end= " << end << endl;
        if(isUsed[cur] == true){
            return;
        }
        if(cur == end){
            cout << "start= " << start << " cur= "<< cur << " end= " << end << " connected" << endl;
            resu.push_back({start,end});
            return;
        }
        
        vector<int>neighBord = figureData[cur];
        for(int i = 0;i  < neighBord.size(); i++){
            isUsed[cur] = true;
            DFS(start,neighBord[i],end);
            isUsed[cur]= false;
        }

    }
    void MakeFigure(vector<vector<int>>& prerequisites)
    {
        for(int i = 0; i< prerequisites.size(); i++){
            int start = prerequisites[i][0];
            int end = prerequisites[i][1];
            figureData[start].push_back(end);
        }
    }
    void PrintFigure()
    {
        auto it = figureData.begin();
        while(it != figureData.end()){
            vector<int>neighBored= it->second;
            cout << it->first << " -> ";
            for(int i= 0; i< neighBored.size(); i++){
                cout << neighBored[i] << " ";
            }
            cout << endl;
            it++;
        }
    }
public:
    unordered_map<int ,vector<int>> figureData;
    int Number;
    vector<pair<int,int>>resu;
    vector<bool>isUsed;

};

int main()
{
    Solution s1;
    int numCourses = 2;
    vector<vector<int>>prerequisites = {};
    vector<vector<int>>queries = {{1,0},{0,1}};
    vector<bool>resu = s1.checkIfPrerequisite(numCourses, prerequisites, queries);

    return 0;
}