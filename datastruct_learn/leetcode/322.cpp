#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, INVAILD_NUM);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            int mintimes = INVAILD_NUM;
            for(int k = 0; k< coins.size(); k++){
                int coin_num = coins[k];
                if( i == coin_num) {
                    mintimes = 1;
                    break;
                }

                

                if( i - coin_num <= 0 ) continue;

                mintimes = min(mintimes, dp[i - coin_num] + 1);
                // cout << "i= " << i << " mintimes= " << mintimes << endl;

                if(mintimes == 1){
                    break;
                }
            }
            
            dp[i] =mintimes ;
        }
        // MyPrintOne(dp);
        if(dp[amount] == INVAILD_NUM) return -1;
        return dp[amount];
    }
private:
    vector<int>dp;
    int INVAILD_NUM = INT32_MAX / 2;
    // int INVAILD_NUM = 1000;
};
int main()
{
    Solution s1;
    // s1.calMaxArray();
    // vector<int>coins = {2};
    // int amount = 3;

    vector<int>coins = {2};
    int amount = 0;

    int resu = s1.coinChange(coins, amount);

    cout << " main resu = " << resu << endl;
    

    cout << "hell22o" << endl;
    return 0;
}