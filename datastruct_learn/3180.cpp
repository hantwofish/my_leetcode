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
    int maxTotalReward(vector<int>& rewardValues) {
        
        rewardValuesBack = rewardValues;
        sort(rewardValuesBack.begin(), rewardValuesBack.end());

        DFSCalSum(0, 0, rewardValuesBack.size());
        
        cout << "maxTotalReward " << " output=  " << output << endl;
        return output;
    }
    void DFSCalSum(const int start, int curLocation ,const int endIndex)
    {
        if(curLocation >= endIndex){
            // cout << "resu= " << resu << " curLocation=  " << curLocation << endl;
            output = max(output, resu);
            return;
        }
        bool flag = false;

        for(int i = curLocation; i < rewardValuesBack.size(); i++){
            if(rewardValuesBack[i] > resu){
                resu += rewardValuesBack[i];
                flag = true;
            }else{
                // return;
            }
            DFSCalSum(start, i + 1, endIndex);

            if(flag){
                resu -= rewardValuesBack[i];
            }
        }
    }
private:
    int resu = 0;
    int output = 0;
    vector<int> rewardValuesBack;

};

int mainFunc()
{
    Solution s1;
    // vector<int> rewardValues = {1,1,3,3};
    // vector<int> rewardValues = {1,6,4,3,2};
    vector<int> rewardValues = {92,15,60,40,49,54,63,65,96,14,70,73,59,20,21,98,81,55,27,4,30,62,33,58,92,16,81,72,21,94,15,92};
    s1.maxTotalReward(rewardValues);

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