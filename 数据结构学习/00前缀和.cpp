#include"../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<set>
#include<unordered_set>

#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>
#include <iterator>

using namespace std;

class Solution{
public:
    int calMaxArray(vector<int>&nums)
    {
        frontSumArry.resize(nums.size(),0);
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) {
                frontSumArry[i] = nums[0];
                continue;
            }
            frontSumArry[i] = frontSumArry[i-1] + nums[i];
        }
        
        return 0;
    }
    // [i, j];, 对应 numsz中索引
    int getSum(int i, int j)
    {
        if(i == 0) return frontSumArry[j];
        return frontSumArry[j] - frontSumArry[i-1];

    }
public:
    vector<int>frontSumArry;

};


int main()
{
    Solution s1;
    vector<int>nums = {-1,1,2,3};

    s1.calMaxArray(nums);
    MyPrintOne(s1.frontSumArry);

    cout << "hello" << endl;
    return 0;
}