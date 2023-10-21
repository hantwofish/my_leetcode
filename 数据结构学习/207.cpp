#include"../STLCOMMON.h"

using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Init(numCourses, prerequisites);
        return true;
    }
    void Init(int numCourses, vector<vector<int>>& prerequisites)
    {
        nodeNumber = numCourses;
        MakeFigure(prerequisites);
        PrintFigure();
        

    }
    void DFS()
    {

    }
    void MakeFigure(vector<vector<int>>& prerequisites)
    {
        for(int i= 0 ; i < prerequisites.size(); i++){
            int pre = prerequisites[i][1];
            int cur = prerequisites[i][0];
            figureData[pre].push_back(cur);
        }

    }
    void PrintFigure()
    {
        auto it = figureData.begin();
        while(it != figureData.end()){
            cout << it->first << " -> ";
            vector<int>nums= it->second;
            for(int i = 0 ; i < nums.size(); i++){
                cout << nums[i] << " ";
            }
            cout << endl;
            it++;   
        }
    }
public:
    unordered_map<int ,vector<int>> figureData;
    int nodeNumber;
    vector<bool>isUsed;
    vector<int>status;// 0未访问，1访问中，2在环中
};

int main()
{
    Solution s1;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    bool resu  = s1.canFinish(numCourses, prerequisites);
    
    return 0;
}