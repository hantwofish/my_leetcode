#include"../../STLCOMMON.h"

using namespace std;

typedef struct {
    int left;
    int right;
} LRNode;

class Solution{
public:
    void FigureInit()
    {
        // FigureMap.insert({1,tem});
        FigureMap.insert({1,{2,4,5}});
        FigureMap.insert({2,{3,7}});
        FigureMap.insert({4,{5}});
        FigureMap.insert({3,{5,8}});
        FigureMap.insert({7,{8}});
        FigureMap.insert({5,{8}});
        FigureMap.insert({8,{-1}});

    }
    void PrintMap()
    {
        auto it = FigureMap.begin();
        while( it!= FigureMap.end() ){
            cout << "key=" << it->first << " | ";
            vector<int> temp = it->second;
            for(int i = 0; i< temp.size();i++){
                cout << temp[i] << " ";
            }
            cout << endl;
            it++;
        }
    }
// 找出起始点到终点的所有路径
    void DFSTrac(int curIndex, int endIndex)
    {
        if(curIndex == -1 || isVisited[curIndex]){
            return;
        }
        if(curIndex == endIndex){
            oneResu.push_back(endIndex);
            allResu.push_back(oneResu);
            oneResu.pop_back();
        }
        oneResu.push_back(curIndex);
        isVisited[curIndex] = true;
        for(int i = 0; i<FigureMap[curIndex].size(); i++ ){
            DFSTrac(FigureMap[curIndex][i], endIndex);
        }
        oneResu.pop_back();
        isVisited[curIndex] = false;
        


    }
    void BFSTrac(int startIndex)
    {

    }
    void PrintResu()
    {
        for(int  i = 0; i< allResu.size(); i++){
            for(int j = 0; j < allResu[i].size(); j++){
                cout << allResu[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

public:
    // unordered_map<int, pair<int, int>> FigureMap;
    unordered_map<int, vector<int>> FigureMap;
    vector<int>oneResu;
    vector<vector<int>>allResu;
    unordered_map<int,bool> isVisited;

};

int main()
{
    Solution s1;
    s1.FigureInit();
    s1.PrintMap();
    s1.DFSTrac(1,8);
    s1.PrintResu();

    


    cout << "result" << endl;
    return 0;
}