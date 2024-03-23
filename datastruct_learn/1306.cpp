#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        N = arr.size();
        isVisited.resize(N, 0);
        vector<int>target;
        for(int i=0; i< arr.size(); i++){
            if(arr[i] == 0){
                target.push_back(i);
                // continue;
            }

            int front_dir = i + arr[i];
            int end_dir = i -arr[i];
            if(front_dir >= 0 && front_dir < N){
                figureMap[i].push_back(front_dir);
            }
            if(end_dir >= 0 && end_dir < N ){
                figureMap[i].push_back(end_dir);
            }

            
        }

        PrintMap(figureMap);
        for(int i= 0; i < target.size(); i++){
            int end_node =target[i];
            resu[end_node] = false;
            isVisited.clear();
            onePath.clear();
            isVisited.resize(N, 0);
            DFS(start, end_node, start, isVisited, onePath);

        }
        
        bool outputVal = true;
        for(int i =0 ; i< target.size(); i++){
            cout << "endNode = " << target[i] << " -> " << resu[target[i]] << endl;
            outputVal &= (resu[target[i]] == 1);
        }
        
        cout << "outputVal = " << outputVal << endl;
        return outputVal;
    }
private:
    void DFS(int start_node , int end_node, int cur_node, vector<int>&isVisited, vector<int>&onePath)
    {
        if(isVisited[cur_node] == true){
            return;
        }
        if(cur_node == end_node){
            onePath.push_back(cur_node);
            resu[cur_node] = true;
            MyPrintOne(onePath);
            onePath.pop_back();
            return;
        }
        onePath.push_back(cur_node);
        isVisited[cur_node] = true;
        vector<int>neighbored = figureMap[cur_node];
        for(int i = 0; i < neighbored.size(); i++){
            DFS(start_node, end_node, neighbored[i], isVisited, onePath);
        }

        onePath.pop_back();
        isVisited[cur_node] = false;
    }   

    void PrintMap(unordered_map<int,vector<int>>figureMap)
    {
        auto it = figureMap.begin();
        while(it != figureMap.end()){
            vector<int>temp = it->second;
            cout << it->first << " | ";
            for(auto &val : temp){
                cout << val << " " ;
            }
            cout << endl;
            it++;
        }
    }
private:
    unordered_map<int,vector<int>>figureMap;
    int N = 0;
    vector<int>isVisited;
    vector<int>onePath;

    unordered_map<int, bool>resu;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    // vector<int>arr = {4,2,3,0,3,1,2};
    // int start = 5;

    // vector<int>arr = {4,2,3,0,3,1,2};
    // int start = 0;

    // vector<int>arr = {3,0,2,1,2};
    // int start = 2;
    vector<int>arr = {0,3,0,6,3,3,4};
    int start = 6;
    s1.canReach(arr, start);
    

    cout << "hell22o" << endl;
    return 0;
}