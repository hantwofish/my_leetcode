#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k = k % N;
        vector<int>behind_vec;
        for(int i = N - k; i < nums.size(); i++){
            behind_vec.push_back(nums[i]);
        }
        print_val(behind_vec);
        for(int i = N - k-1 ; i >= 0; i--){
            nums[i+k] = nums[i];
        }

        int index = 0;
        for(auto val : behind_vec){
            nums[index] = val;
            index++;
        }
        print_val(nums);
        return;
    }
    void print_val(vector<int>nums)
    {
        for(auto i: nums){
            cout << i << " ";
        }
        cout << endl;
    }
};


int main()
{
    Solution S1;
    // vector<int>nums = {1,2,3,4,5,6,7};
    // int k = 3;

      vector<int>nums = {-1,-100,3,99};
    int k = 2;
    S1.rotate(nums, k);

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp