#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        dp.resize(N+1, 0);
        if(N<=1) return 0;
        dp[1] = dp[0] = 0;
        for(int i =2; i<= N; i++){
            // case1: 跳一步
            int case1 = dp[i-1] + cost[i-1];

            // case2: 跳两步
            int case2 = dp[i-2] + cost[i-2];
            if(case1 < case2) {
                cout << "i= "<< i << " " << i-1 << endl;
            }else {
                cout << "i= "<< i << " " << i-2 << endl;
            }
            
            dp[i] = min(case1,case2);

        }
        MyPrintOne(dp);
        cout << "resu=  " << dp[N] <<  endl;


        return dp[N];
    }
public:
    vector<int>dp;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<int>cost = {10,15,20};
    s1.minCostClimbingStairs(cost);

    

    cout << "hell22o" << endl;
    return 0;
}