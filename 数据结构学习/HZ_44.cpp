// #include"../STLCOMMON.h"
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
    int calMaxArray(int& n, vector<int>&nums)
    {
        vector<int>dp(n+1,0);// 定义数组,以i 结尾的长度
        int maxresu = 0;
        for(int i = 0; i < n; i++){
            if(i == 0){
                dp[i] =1;
                continue;
            }
            dp[i] = 1;
            for(int j = 0; j < i; j++ ){
                if(nums[j] < nums[i] ){
                    dp[i] = max(dp[i], dp[j]+ 1);;
                }
            }
            maxresu = max(maxresu,dp[i]);
        }
        // MyPrintOne(dp);
        // cout << "maxResu= " << maxresu << endl;
        // cout << "dp[n-1]= " << dp[n-1] << endl;
        return maxresu;
    }
};


void getInputData(int& n, vector<int>&nums)
{
    cin >> n;
    nums.clear();
    for(int i =0; i< n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    // MyPrintOne(nums);
    
}

int main()
{
    Solution s1;
    
    vector<int>nums = {3841, 2674 ,2268 ,6911 ,5952 ,3656 ,4655 ,8208 ,5661, 304};
    int n = nums.size();
    getInputData(n ,nums);
    int resu = s1.calMaxArray(n, nums);
    cout  << resu << endl;
    

    // cout << "hello" << endl;
    return 0;
}