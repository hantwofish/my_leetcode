#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<int>min_nums(N, prices[0]);
        vector<int>max_nums(N, prices[N-1]);
        for(int i = 1; i< N; i++){
            min_nums[i] = min(min_nums[i-1], prices[i]);
        }
        for(int i = N-2; i >= 0; i--){
            max_nums[i] = max(max_nums[i+1], prices[i]);
        }
        MyPrintOne(min_nums);
        MyPrintOne(max_nums);
        int output_val = 0;
        for(int i = 0; i < N; i++){
            output_val = max(output_val, max_nums[i] - min_nums[i]);
        }
        cout << "output_val = " << output_val << endl;

        return 0;
    }
};


int main()
{
    vector<int>nums= {7,1,5,3,6,4};
    Solution s1;
    s1.maxProfit(nums);
    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp