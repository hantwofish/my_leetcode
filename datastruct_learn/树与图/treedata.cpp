#include"../../STLCOMMON.h"

using namespace std;

typedef struct {
    int left;
    int right;
} LRNode;

class Solution{
public:
    void TreeInirt()
    {
        LRNode tem;
        tem.left = 3;
        tem.right = 5;
        // TreeMap.insert({1,tem});
        TreeMap.insert({1,{3,5}});
        TreeMap.insert({3,{2,7}});
        TreeMap.insert({5,{10,12}});
        TreeMap.insert({12,{13,-1}});
        TreeMap.insert({2,{-1,-1}});
        TreeMap.insert({7,{-1,-1}});
        TreeMap.insert({10,{-1,-1}});
        TreeMap.insert({13,{-1,-1}});

    }
    void PrintMap()
    {
        auto it = TreeMap.begin();
        while( it!= TreeMap.end() ){
            cout << "key=" << it->first << " " << it->second.left << " " << it->second.right << endl;
            it++;
        }
    }

    void DFSTrac(int startIndex)
    {
        if( TreeMap.find(startIndex) ==TreeMap.end() ){
            return;
        }
        cout << startIndex << endl;
        DFSTrac(TreeMap[startIndex].left);
        DFSTrac(TreeMap[startIndex].right);


    }
    void BFSTrac(int startIndex)
    {
        queue<int>treeQue;
        treeQue.push(startIndex);
        while(!treeQue.empty()){
            cout << "pop=" << treeQue.front() << endl;
            int front = treeQue.front();
            // if(TreeMap.find(startIndex) !=TreeMap.end()  ){
                if(  TreeMap[front].left != -1){
                    // cout << "left=" << TreeMap[front].left << endl;
                    treeQue.push(TreeMap[front].left);
                }
                if(  TreeMap[front].right != -1){
                    // cout << "right=" << TreeMap[front].right << endl;
                    treeQue.push(TreeMap[front].right);
                }
                
            // }
            treeQue.pop();
        }
    }

private:
    // unordered_map<int, pair<int, int>> TreeMap;
    unordered_map<int, LRNode> TreeMap;

};

int main()
{
    Solution s1;
    s1.TreeInirt();
    s1.PrintMap();

    s1.DFSTrac(1);
    s1.BFSTrac(1);

    cout << "result" << endl;
    return 0;
}