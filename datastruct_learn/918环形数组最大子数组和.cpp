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

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxvla = maxValAryy(nums);
        int minval = minValArry(nums);
        int sumval = 0;
        for(auto i : nums){
            sumval += i;
        }
        cout << "maxval= " << maxvla << " minval= " << minval << " sum= " << sumval << endl;
        if(maxvla < 0)  return maxvla;
        int ringmax = sumval - minval;
        return max(maxvla, ringmax);

    }
    int maxValAryy(vector<int>& nums)
    {
        // vector<int>dp(N+1,INT32_MIN); //  以nums[i] 为结尾的最大子数组和
        // for(int i = 0; i <N;i++){
        //     if(i == 0) {
        //         dp[i]= nums[0];
        //         continue;
        //     }
        //     dp[i] =  max(nums[i], dp[i-1] + nums[i]);
        // }
        int curMax  = nums[0];
        int globalMax = curMax;
        for(int i =1 ; i< nums.size(); i++){
            curMax = max(curMax+ nums[i], nums[i]);
            globalMax = max(globalMax, curMax);
        }
        return globalMax;
    }
    int minValArry(vector<int>& nums)
    {
        int curMin = nums[0];
        int globalMin = curMin;
        for(int i = 1; i < nums.size(); i++){
            curMin = min(curMin+nums[i], nums[i]);
            globalMin = min(globalMin, curMin);
        }
        return globalMin;

    }
};

int main()
{
    Solution s1;
    vector<int>nums =  {5,-3,5};
    int resui = s1.maxSubarraySumCircular(nums);
    cout << " resu = " << resui << endl;

    cout << "hello" << endl;
    return 0;
}