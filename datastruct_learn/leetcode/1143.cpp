#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution{
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        dp.resize(n+1,vector<int>(m+1,0));

        // for(int j = 0; j< m; j++){
        //     if(j == 0){
        //         dp[0][j] = (text1[0] == text2[j]);
        //         continue;
        //     }
        //     dp[0][j] = dp[0][j-1];
        // }
        // for(int i= 0; i< n;i++){
        //     if(i == 0){
        //         dp[i][0] = (text2[0] == text1[i]);
        //         continue;
        //     }
        //     dp[i][0] = dp[i-1][0];
        // }
        // MyPrintTwo(dp);


        
        for(int i = 1; i <= n;i++){
            for(int j= 1; j<= m; j++){
                int case1 = 0;
                // if(text1[i] == text2[j]) case1 =1;
                // dp[i][j] = max(dp[i-1][j-1]+ case1, max(dp[i-1][j],dp[i][j-1]));
                dp[i][j] =  max(dp[i-1][j],dp[i][j-1]);
                if(text1[i -1] == text2[j-1]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                }

            }
        }
        MyPrintTwo(dp);
        return dp[n][m];

    }
private:
    vector<vector<int>>dp; // dp[i][j], 以text1[0:i] text2[0:j] 为区间的最长公共子序列长度
    /*
    case1: text1[i] == text2[j]
        dp[i][j] = dp[i-1][j-1]+1
    case2: !=
        dp[i][j] = max(dp[i-1][j],dp[i][j-1])
    */
};




int main()
{
    Solution s1;

    string text1 = "abc";
    string text2 = "def";
    s1.longestCommonSubsequence(text1, text2);

    

    cout << "hell22o" << endl;
    return 0;
}