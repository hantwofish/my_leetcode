#include"../STLCOMMON.h"
using namespace std;
/*
f(2n) A->C
= f(2(n-1)) 从上面 2(n-1) A->B
+ 2 下面最大的 A->C 
+ f(2(n-1)) B->C
*/

class Solution{
public:
    void CalNuns(int n)
    {
        vector<int>dp(n+1,0); // 2n 个汉诺塔  A->C 的个数
        for(int i = 1; i<=n ; i++){
            dp[i] = 2 * dp[i-1] + 2; 
        }
        cout << dp[n];

    }

};

int main()
{
    Solution s1;
    int n =2;
    cin >> n;
    s1.CalNuns(n);
    // cout << "end" << endl;
    return 0;
}