#include"../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<set>
#include<unordered_set>

#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>
#include <iterator>

using namespace std;

class Solution{
public:
    vector<int>calMinVal(vector<int>& parents, vector<int>&nums)
    {
        N = parents.size();
        cout << "N= " << N << endl;
        for(int i= 0; i < parents.size(); i++){
            int father=  parents[i];
            figureData[father].push_back(i);
            traVal[i] = nums[i];
        }
        auto it = figureData.begin();
        while(it != figureData.end()){
            cout << it->first << " -> " ;
            vector<int>temp =it->second;
            for(int i =0; i< temp.size(); i++){
                cout << temp[i] << " ";
            }
            cout << endl;
            it++;
        }

        vector<int>enge(N,0); // 基因
        // 计算 每个根下面的所有子节点
        int i= 0;
        for(int i= 0; i < N;i++){
            vector<int> temp = calAllNodeFromOneNode(0);
            MyPrintOne(temp);
            vector<int>tempJiyin(N,0);
            int j =0;
            for( j =0; j < temp.size(); j++){
                tempJiyin[j] = traVal[j];
            }
            sort(tempJiyin.begin(), tempJiyin.end());
            cout << "tempJiyin" <<endl;
            MyPrintOne(tempJiyin);
            cout << "tempJiyin" <<endl;
            for(int k =1; k <= 100000; k++){
                if(find(tempJiyin.begin(), tempJiyin.end(), k) == tempJiyin.end()){
                    enge[i] = k;
                    cout << "i= " << i << " jiyin= " << k << endl;
                    break;
                }
            }
        }
        MyPrintOne(enge);
        
        return {};
    }
    // 从一个根节点找到所有的子树节点
    vector<int>calAllNodeFromOneNode(int start)
    {
        // cout << "calAllNodeFromOneNode" << endl;
        isUsed.resize(N,false);
        // cout << "calAllNodeFromOneNode " << isUsed.size() << endl;
        set<int>dig;
        dig.insert(start);
        DFS(start, start, dig);
        // cout << "calAllNodeFromOneNode  DFS" << endl;
        for(auto it = dig.begin(); it != dig.end(); it++){
            cout << *it << " ";
        }
        cout << endl;

        vector<int>resu(dig.begin(), dig.end());
        return resu;
    }
    void DFS(const int start, int cur, set<int>&dig)
    {
        cout << "DFS start= " << start << " cur= " << cur << endl;
        if(isUsed[cur] == true){
            cout << "isUsed" << endl;
            return;
        }
        // cout << "isUsed2" << endl;
        if(figureData.find(cur) == figureData.end()){
            cout << " not found" << endl;
            return;
        }
        isUsed[cur] = true;
        vector<int>neigh = figureData[cur];
        cout << "neigh size= " << neigh.size() << endl;
        for(int i = 0; i< neigh.size(); i++){
            dig.insert(neigh[i]);
            cout << "i= " << i << " neigh= "  << neigh[i] << endl;
            DFS(start, neigh[i], dig);
        }

    }


public:
    unordered_map<int, vector<int>> figureData;
    unordered_map<int, int> traVal;
    vector<bool>isUsed;
    int N=0;
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    vector<int>parents = {-1,0,0,2};
    vector<int>nums = {1,2,3,4};
    vector<int>resu =s1.calMinVal(parents,nums); 
    // cout << INT32_MAX << endl;

    // cout << "hello" << endl;
    return 0;
}