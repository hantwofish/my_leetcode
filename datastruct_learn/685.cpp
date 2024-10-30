#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;




class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        class UnionFind f1(1005);
        for(int i = 0; i<  edges.size(); i++){
            int start = edges[i][0];
            int end = edges[i][1];
            if(f1.find_fa(start) == f1.find_fa(end)){
                cout << " is reden " << "[" << start << " " << end  << " ] " << f1.find_fa(start) << endl;
                return {start, end};
                break;
            } else {
                f1.unionNode(start, end);
                cout << " is  " << "[" << start << " " << end  << " ] " << f1.find_fa(start) << "  " << f1.find_fa(end)<< endl;
            }
        }
        return {};
    }
};

int mainFunc()
{
    Solution s1;
    vector<vector<int>>nums = {{2,1},{3,1},{4,2},{1,4}};
    s1.findRedundantDirectedConnection(nums);

    return 0;
}

int main()
{

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe