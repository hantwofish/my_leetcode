#include"../STLCOMMON.h"
#include"../COMMONALO.h"
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
/*
https://leetcode.cn/problems/maximum-earnings-from-taxi/solutions/2558504/jiao-ni-yi-bu-bu-si-kao-dong-tai-gui-hua-k15a/
*/

/*
以dp[i] 定义以 i 为终点的最大收益
case1:
    i 无乘客下车

case2:
    i 有乘客下车：找到所有在 i(end = i) 下车的情况，求最大值
    max(dp[start] + (end -start + tri[j]))

*/

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        if(n <=1){
            return 0;
        }
        for(int i = 0; i < rides.size();i++){
            myMap[rides[i][1]].push_back(i);
        }


        dp.resize(n+1,0);
        for(int i = 2; i <= n ;i++){
            // case1 
            long long case_1 = dp[i-1];
            // case2 
            long long case_2 = 0;
            vector<int>endTempVec = myMap[i];

            for(int k = 0; k< endTempVec.size();k++){
                // if(rides[j][1] != i) continue;
                int j = endTempVec[k];
                long long temp = dp[rides[j][0]] + (i - rides[j][0] + rides[j][2]);
                case_2 = max(case_2, temp);
            }
            dp[i] = max(case_1, case_2);

        }
        return dp[n];

    }
public:
    vector<int>dp;
    unordered_map<int, vector<int>>myMap;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    int n = 20;
    vector<vector<int>>rides = {{1,6,1},{3,10,2},{10,12,3},{11,12,2},{12,15,2},{13,18,1}};
    long long resu = s1.maxTaxiEarnings(n,rides);
    cout << "resu= " << resu << endl;

    

    cout << "hello word" << endl;
    return 0;
}