#include"../STLCOMMON.h"

using namespace std;

// DFS 回溯
class Solution2 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Init(numCourses, prerequisites);
        vector<int>oneCile;
        for(int i = 0; i < nodeNumber; i++){
            DFS(i,i,i,oneCile);
        }

        int N= cicleCondition.size();
        if(N== 0){
            return true;
        }
        
        return false;
    }
    void Init(int numCourses, vector<vector<int>>& prerequisites)
    {
        nodeNumber = numCourses;
        isUsed.resize(nodeNumber,false);
        status.resize(nodeNumber,0);
        MakeFigure(prerequisites);
        PrintFigure();
        

    }
    void DFS(int start, int cur, int end, vector<int>&oneCile)
    {
        // cout << "DFS " << " start= " << start << " cur= " << cur << " end= " << end << endl; 
        // 如果当前节点的状态为 1 ，则访问到了先前的节点，这是一个环
        if(status[cur]){
            cout << "cur= " << cur << endl;
            oneCile.push_back(cur);
            MyPrintOne(oneCile);
            cicleCondition.push_back(oneCile);
            oneCile.pop_back();
        }
        //  
        if(isUsed[cur]){
            return;
        }

        oneCile.push_back(cur);
        vector<int>neighBord= figureData[cur];
        for(int i = 0; i < neighBord.size(); i++){
            isUsed[cur] = true;
            status[cur] = 1;
            DFS(start,neighBord[i], end,oneCile);
            isUsed[cur] = false;
            status[cur] = 0;

        }
        oneCile.pop_back();

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
    vector<int>status;// 0未访问，1访问中，2安全的，不在环里面
    vector<vector<int>> cicleCondition; // 记录每一个环的情况
};

// 拓扑排序
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()){
            return true;
        }
        set<int>nodeSet;
        set<int>nodeSetResu;

        Init(numCourses, prerequisites);
        deque<int>que;
        // 入度为0 的入队
        for(auto it = figurData.begin(); it != figurData.end(); it++){
            nodeSet.insert(it->first);
            if(it->second.first == 0){
                que.push_back(it->first);
            }
        }

        while(!que.empty()){
            auto top =  que.front();
            que.pop_front();
            cout << "pop= " << top << endl;
            oneResu.push_back(top);
            
            // 相邻节点的入度减一
            for(int i = 0; i<  figurData[top].second.size(); i++){
                int key = figurData[top].second[i];
                figurData[key].first--;
            }

            figurData.erase(top);

            // 入度为0的，入队
            for(auto it = figurData.begin(); it != figurData.end(); it++){
                if(it->second.first == 0){
                    cout << "dig=0 push " << it->first << endl;
                    if(find(que.begin(),que.end(),it->first ) == que.end()){
                        que.push_back(it->first);
                    }
                    
                }
            }

        }

        MyPrintOne(oneResu);
        for(auto i: oneResu){
            nodeSetResu.insert(i);
        }

        return nodeSet==nodeSetResu;
    }
    void Init(int numCourses, vector<vector<int>>& prerequisites)
    {
        nodeNum = numCourses;
        for(int i = 0; i< prerequisites.size(); i++){
            int pre = prerequisites[i][1];
            int end = prerequisites[i][0];
            figurData[pre].second.push_back(end);
            figurData[end].first++;
        }

        PritFigureData();
    }
    void PritFigureData()
    {
        auto it = figurData.begin();
        while(it != figurData.end()){
            cout << it->first << " | dig= " << it->second.first << " | ";
            vector<int>temp =it->second.second;
            for(int i = 0; i < temp.size(); i++){
                cout << temp[i] << " ";
            }
            cout << endl;
            it++;
        }

    }
public:
    int nodeNum;
    unordered_map<int,pair<int,vector<int>>> figurData;
    vector<int>oneResu;
};
int main()
{
    Solution s1;
    int numCourses = 5;
    vector<vector<int>> prerequisites = {
        {1,4 },
        {2,4 },
        {3,1 },
        {3,2 },
        };
    bool resu  = s1.canFinish(numCourses, prerequisites);
    cout << "resu= " << resu << endl;
    
    return 0;
}