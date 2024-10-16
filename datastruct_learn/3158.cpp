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
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int>u_map;
        for(int i = 0; i< nums.size(); i++){
            u_map[nums[i]]++;
        }
        vector<int>result;
        auto it = u_map.begin();
        while(it != u_map.end()){
            if(it->second == 2){
                result.push_back(it->first);
            }
            it++;
        }
        if(result.empty()) return 0;
        int out_val= result[0];
        for(int i = 1; i < result.size();i++){
            out_val = out_val xor result[i];
        }
        return out_val;
    }
};

int mainFunc()
{
    Solution s1;
    vector<int> nums = {1,2,2,1};
    s1.duplicateNumbersXOR(nums);
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