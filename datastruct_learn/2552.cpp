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
    long long countQuadruplets(vector<int>& nums) {
        int resu = 0;
        for(int i = 0; i<= nums.size()-4; i++){
            for(int j = i+1; j <= nums.size()-3; j++){
                for(int k = j+1; k <= nums.size()-2; k++){
                    for(int l = k+1; l <= nums.size()-1; l++){
                        if(nums[i] < nums[k] &&
                            nums[k] < nums[j] &&
                            nums[j] < nums[l] ){
                        resu++;
                        }


                    }
                }


            }
            cout << "i= " << i << endl;

        }
        cout <<"resu= " << resu <<endl;
        return resu;
    }
};

int mainFunc()
{
    Solution s1;
    vector<int>nums =  {1,3,2,4,5};
    s1.countQuadruplets(nums);
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