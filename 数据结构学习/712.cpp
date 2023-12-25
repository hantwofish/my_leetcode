#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        dp.resize(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j= 1; j <= m ;j++ ){
                char s1c = s1[i-1];
                char s2c = s2[j-1];
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(s1c == s2c){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (s1c- '\0'));
                }
            }
        }
        MyPrintTwo(dp);
        cout << "dp[n][m]= " << dp[n][m] << endl;
        int allVal =0;
        for(auto c: s1){
            allVal += (c - '\0');
        }
        for(auto c: s2){
            allVal += (c - '\0');
        }
        // cout << "allval= " << allVal << " " << allVal - 2* dp[n][m] << endl;

        return allVal - 2* dp[n][m];

    }
private:
    vector<vector<int>>dp; // 记录s1[0:i] s2[0:j] 公共子串最大的ASSIC 值
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    string s1s=  "delete";
    string s2s = "leet";
    s1.minimumDeleteSum(s1s,s2s);

    cout << "s-0= " << ('s'-'\0') << endl;
    

    cout << "hell22o" << endl;
    return 0;
}