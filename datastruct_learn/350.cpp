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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        for(auto i : nums1){
            mapVec[i]++;
        }
        set<int>resu;
        for(int i =0; i< nums2.size(); i++){
            if(mapVec[nums2[i]] > 0){
                resu.insert(nums2[i]);
            }
        }
        vector<int>outVal(resu.begin(), resu.end());
        return outVal;
    }
private:
    unordered_map<int,int>mapVec;
};

int mainFunc()
{
    Solution s1;

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