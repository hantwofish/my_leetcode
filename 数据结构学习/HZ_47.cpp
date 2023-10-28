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
    int calMaxValue(int v, int n, vector<vector<int>>&nums)
    {
        // f(i)(j) 在背包容量为 j 的情况下，在前 i 个物品中选取的最大值
        vector<vector<int>>dp(n+1, vector<int>(v+1,0));
        nums.insert(nums.begin(),vector<int>(v+1,0));

        
        for(int i =1; i<= n ; i++){ // 物品个数
            for(int j = 1; j <= v; j++){ // 总容量
                // cout << "i = " << i << " j= " << j << endl;
                dp[i][j] = dp[i-1][j];
                if( j < nums[i][0] ){
                    // cout << "continue i = " << i << " j= " << j << endl;
                    continue;
                }
                // cout << "i = " << i << " j- nums[i][0]= " << j- nums[i][0] << endl;
                int right = dp[i-1][j- nums[i][0]] + nums[i][1];
                // cout << "dp[i][j]= " << dp[i][j] << " right= " << right << endl;
                
                dp[i][j] = max(dp[i][j], right);
            }
        }

        // MyPrintTwo(dp);
        cout  << dp[n][v] << endl;


        return 0;
    }
public:

};

void getInputData(int &v, int& n, vector<vector<int>>&nums)
{
    nums.clear();
    cin >> v >> n;
    for(int i = 0; i < n ; i++){
        int weight ;
        int val;
        cin >> weight >> val;
        nums.push_back({weight,val});
    }
    // cout << "v= " << v << " n= " << n << endl;
    // MyPrintTwo(nums);
}

int main()
{
    Solution s1;
    int n = 4;
    int v =15;
    vector<vector<int>>data{
        {4,10},{3,7},{12,12},{9,8}
    };
    // getInputData(v, n, data);
    s1.calMaxValue(v, n,data);
    

    // cout << "hello" << endl;
    return 0;
}