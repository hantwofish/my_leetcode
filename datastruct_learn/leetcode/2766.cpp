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
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int,int>mapvec;
        for(auto i : nums){
            mapvec[i]++;
        }
        for(int i = 0; i< moveFrom.size(); i++){
            int from = moveFrom[i];
            int to = moveTo[i];
            if(from == to) continue;
            mapvec[to] += mapvec[from];
            mapvec[from] = 0;
        }
        auto it = mapvec.begin();
        vector<int>vec;
        while(it!= mapvec.end()){
            int locatin = it->first;
            int num = it->second;
            cout << "location = " << locatin << " num= " << num << endl;
            // for(int i = 0; i < num; i++){
            //     vec.push_back(locatin);
            // }
            if(num > 0){
                vec.push_back(locatin);
            }
        
            it++;
        }
        sort(vec.begin(), vec.end());
        MyPrintOne(vec);
        return vec;
    }
};

int mainFunc()
{
    Solution s1;
    // vector<int> nums = {1,1,3,3};
    // vector<int> moveFrom = {1,3};
    // vector<int> moveTo = {2,2};
    vector<int> nums = {3,4};
    vector<int> moveFrom = {4,3,1,2,2,3,2,4,1};
    vector<int> moveTo = {3,1,2,2,3,2,4,1,1};
    s1.relocateMarbles(nums, moveFrom, moveTo);

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