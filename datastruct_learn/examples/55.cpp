#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        if(N == 1) return true;
        vector<int>max_depth(N, 0);  // 截止到第i的位置，能跳的最远距离
        max_depth[0] = 0 + nums[0];
        if(max_depth[0] ==0){
            return false;
        }

        for(int i = 1; i < N; i++){
            max_depth[i] = max(max_depth[i-1], i+ nums[i]);
            if(max_depth[i] == i && i < N-1){
                return false;
            }
        }
        // MyPrintOne(max_depth);
        if(max_depth[N-1]>= N-1){
            return true;
        }


        return false;
    }
};

int main()
{
    vector<int>nums = {2,3,1,1,4};
    // vector<int>nums = {3,2,1,0,4};
    Solution s1;
    bool flag =  s1.canJump(nums);
    if(flag){
        cout << "main true" << endl;

    }else{
        cout << "main false" << endl;
    }

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp