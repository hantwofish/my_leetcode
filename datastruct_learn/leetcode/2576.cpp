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
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int resu = 0;
        while(nums.size() >0){
            int temp = nums[0];
            bool finded = false;
            for(int i = 0; i< nums.size(); i++){
                if(nums[i] * 2 <= temp ){
                    cout << "erase :" << *(nums.begin()+i) << " temp= " << temp << endl;
                    nums.erase(nums.begin()+i);
                    nums.erase(nums.begin());
                    finded = true;
                    resu +=2;
                }
            }
            if(finded == false){
                break;
            }
        }
        cout <<"resu= " << resu <<endl;
        return resu;
        
    }
};

int mainFunc()
{
    Solution s1;
    // vector<int>nums= {3,5,2,4};
    // vector<int>nums= {9,2,5,4};
    vector<int>nums= {1,78,27,48,14,86,79,68,77,20,57,21,18,67,5,51,70,85,47,56,22,79,41,8,39,81,59,74,14,45,49,15,10,28,16,77,22,65,8,36,79,94,44,80,72,8,96,78,39,92,69,55,9,44,26,76,40,77,16,69,40,64,12,48,66,7,59,10};
    s1.maxNumOfMarkedIndices(nums);

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