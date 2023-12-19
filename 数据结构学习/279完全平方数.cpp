#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT32_MAX);
        for(int i = 1; i<= n; i++){
            if(isVaild(i)){
                dp[i] = 1;
                continue;
            }
            for(int k = 1; k *k < i; k++){
                dp[i] = min(dp[i], dp[k*k] + dp[i- k*k]);
            }
            MyPrintOne(dp);
        }
        cout << "resu= " << dp[n] << endl;
        return dp[n];


    }
    bool isVaild(int n)
    {
        int temp = sqrt(n);
        return temp*temp == n;
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    int n = 13;
    s1.numSquares(n);

    

    cout << "hell22o" << endl;
    return 0;
}