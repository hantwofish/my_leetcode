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
        vector<int>resu;
        for(int i =0; i< nums2.size(); i++){
            if(mapVec[nums2[i]] > 0){
                resu.push_back(nums2[i]);
                mapVec[nums2[i]]--;
            }
        }

        MyPrintOne(resu);
        return resu;
    }
private:
    unordered_map<int,int>mapVec;
};

int mainFunc()
{
    Solution s1;
    vector<int>nums1 = {4,9,5};
    vector<int>nums2 = {9,4,9,8,4};
    s1.intersect(nums1, nums2);

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