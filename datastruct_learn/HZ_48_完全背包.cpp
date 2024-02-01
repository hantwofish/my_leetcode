//  #include"../STLCOMMON.h"
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

// f[i][j] 背包容量为j，在前 i个物品中选取的最大值

class Solution{
public:
    int calMaxArrVale(int n, int V, vector<vector<int>>&nums)
    {
        vector<vector<int>>dp(n+1, vector<int>(V+1, 0));
        for(int i = 1; i<= n; i++){
            for(int j = 1; j <= V; j++){
                // 没有选第 I 件商品
                int temp1 = dp[i-1][j];
                // 选了第 I 件商品, 继续选的时候在前I 件中选
                int temp2 = 0;
                if( j >= nums[i -1][0]) {
                    temp2 = dp[i][j- nums[i -1 ][0]] + nums[i -1][1];
                }

                dp[i][j] = max(temp1, temp2);
            }
        }
        // cout << dp[n][V] << endl;
        // cout << "end" << endl;
        return dp[n][V];
    }
};


void getInputData(int& n, int& v, vector<vector<int>>&nums)
{
    nums.clear();
    cin >> n >> v;
    int a, b;
    for(int i = 0; i< n; i++){
        cin >> a >> b;
        nums.push_back({a,b});
    }
    
}

int main()
{
    Solution s1;
    
    int n = 4;
    int V = 15;

    vector<vector<int>> nums={
        {4, 10}, {3, 7}, {12, 12}, {9,8}
    };
    getInputData(n, V, nums);
    int resu = s1.calMaxArrVale(n,V, nums);
    cout << resu << endl;

    

    // cout << "hello" << endl;
    return 0;
}