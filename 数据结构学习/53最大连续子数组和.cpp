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

class  Solution{
public:
    int maxSubArray(vector<int>&nums)
    {
        int N = nums.size();
        vector<int>dp(N+1,INT32_MIN); //  以nums[i] 为结尾的最大子数组和
        for(int i = 0; i <N;i++){
            if(i == 0) {
                dp[i]= nums[0];
                continue;
            }
            dp[i] =  max(nums[i], dp[i-1] + nums[i]);
        }
        int resu = INT32_MIN;
        for(auto  i : dp){
            resu = max(resu, i);
        }
        return  resu;
    }


};

void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    deque<int>ps;
    
    

    cout << "hello" << endl;
    return 0;
}