#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
/*
dp[i] 代表是否可以获胜
n = 5;
1 dp[4]=0 对方失败，己方获胜
2 dp[3]=1 对方获胜，己方失败 
3 dp[2]=2 对方获胜，己方失败 
*/

class Solution {
public:
    bool canWinNim(int n) {
        vector<bool>resu(n + 1, 0);
        for(int i = 1; i<= n; i++){
            if( i <= 3) {
                resu[i] = true;
                continue;
            }
            bool flag = 0;
            flag |= (!resu[i-1]) || (!resu[i-2]) || (!resu[i-3]);
            // for(int j = 1; j<= 3; j++){
            //     if( resu[i-j] == 0 ){
            //         flag = 1;
            //         break;
            //     }
            // }
            resu[i] = flag;
        }

        return resu[n];
    }
};


int main()
{
    Solution s1;
    int n = 2;
    bool flag = s1.canWinNim(n);

    

    cout << "flag= " << flag  << endl;
    return 0;
}