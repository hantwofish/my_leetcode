#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class Solution {
public:
    int minDays(int n) {
        dp.resize(n+ 2, 0);
        for(int i = 1; i <= n ; i++){
            int tiems = dp[i -1];
            if(i % 2 == 0){
                tiems = min(tiems,dp[i /2]);
            }
            if(i % 3 == 0){
                tiems = min(tiems,dp[i /3]);
            }
            dp[i] = 1 + tiems;
        }
        // MyPrintOne(dp);
        cout << "resu= " << dp[n] << endl;
        return dp[n];
    }
    vector<int>dp; //  n 个橘子 需要的最少天数
};
 

int main()
{
    Solution s1;
    s1.minDays(22479359);
    cout << "hell22o" << endl;
    return 0;
}