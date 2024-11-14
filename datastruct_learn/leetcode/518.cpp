#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N  = coins.size();
        vector<vector<int>>dp( N+1 ,vector<int>(amount+1 , 0) );

        coins.insert(coins.begin(), 0);
        // base case
        for(int i = 0; i <= N ;i++)
            dp[i][0]= 1;

        for(int  i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= amount ; j++)\
            {
                // 当前 硬币 值 为 coins[i];
                if(j < coins[i])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];  // 不选择 与 选择 两种情况
            }

        return dp[N][amount];
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}