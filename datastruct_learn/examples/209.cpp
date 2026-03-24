#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
// #include "../INCLUDE/TREE.h"

using namespace std;

// 给定一个含有 n 个正整数的数组和一个正整数 target 。

// 找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。
// 如果不存在符合条件的子数组，返回 0 。

// 示例 1：

// 输入：target = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 示例 2：

// 输入：target = 4, nums = [1,4,4]
// 输出：1
// 示例 3：

// 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
// 输出：0


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size();
        int start_index = 0;
        int end_index = start_index + 1;
        int sum_all = 0;
        for(int i = 0; i< N ; i++){
            if(nums[i] >= target) return 1;
            sum_all+= nums[i];
        }
        if(sum_all == target ) return N;
        if(sum_all < target) return 0;
        int result = N;

        for(int i = 0; i< N -1 ; i++){
            cout << "i= " << i << endl;
            start_index = i;
            end_index = start_index + 1;
            int sum_val = nums[start_index]  ;
            while( start_index < N && end_index < N &&   sum_val < target){
                sum_val += nums[end_index];
                if(  sum_val >= target ){
                    cout << "start_index= " << start_index << " end_index= " << end_index << endl;
                    result = min(result ,end_index - start_index +1);
                    break;
                }
                if(end_index >= N){
                    break;
                }

                end_index++;
            }

            
            
        }

        return result;
    }
};

int main()
{
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    Solution s1;
    s1.minSubArrayLen(target, nums);

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp