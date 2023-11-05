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

// f[i][j] 背包容量为j，在前 i个物品中选取的最大值

class Solution{
public:
    int calMaxArrVale(int n, int V, vector<vector<int>>&nums)
    {
        n =  nums.size();
        vector<vector<int>>dp(n+1, vector<int>(V+1, 0));
        for(int i = 1; i<= n; i++){
            for(int j = 1; j <= V; j++){
                // 没有选第 I 件商品
                int temp1 = dp[i-1][j];
                // 选了第 I 件商品, 继续选的时候在前I -1件中选
                int temp2 = 0;
                if( j >= nums[i -1][0]) {
                    temp2 = dp[i-1][j- nums[i -1 ][0]] + nums[i -1][1];
                }

                dp[i][j] = max(temp1, temp2);
            }
        }
        // cout << dp[n][V] << endl;
        // cout << "end" << endl;
        return dp[n][V];
    }
};


void getInputData( int& v, int& n, vector<vector<int>>&nums)
{
    nums.clear();
    cin  >> v >> n;
    int a, b, c;
    for(int i = 0; i< n; i++){
        cin >> a >> b >> c;
        for(int k = 0; k < c; k++){
            nums.push_back({a,b});
        }
        
    }
    // MyPrintTwo(nums);

    
    
}

int main()
{
    Solution s1;
    int resu = 0;
    
    int V = 15;
    int n = 4;

    vector<vector<int>> nums={
        {4, 10,5}, {3, 7, 4}, {12, 12, 2}, {9,8, 7}
    };
    getInputData( V, n, nums);
    resu = s1.calMaxArrVale(n,V, nums);
    cout << resu << endl;

    

    // cout << "hello" << endl;
    return 0;
}