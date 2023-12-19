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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int N = stations.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1,0)); // dp[i][j] [0,i-1]范围内，最多加 j次油，到达的最大距离
        
        dp[0][0] = stations[0][1];

        for(int i= 1;i< stations.size();i++){
            for(int j= 1; j <= i; j++){
                // case1 不取 j-1 加油站
                int case_1 =dp[i-1][j];
                // case2
                int case_2 = 0;
                if(dp[i-1][j-1] >= stations[i][0] - stations[i-1][0]){
                    case_2 = dp[i-1][j-1] + stations[i-1][1];
                }
                dp[i][j] = max(case_1, case_2);

            }
        }
        MyPrintTwo(dp);



        return 0;
    }
};


int main()
{
    Solution s1;
    int target = 100;
    int startFuel = 10;
    vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};
    int resu  =  s1.minRefuelStops( target,  startFuel, stations);



    cout << "hello" << endl;
    return 0;
}