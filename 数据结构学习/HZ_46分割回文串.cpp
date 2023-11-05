/*
给出一个字符串，问切最少切几刀，使得分成的每一部分都是
回文串（单一字符是回文串）
*/

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

class Solution{
public:
    int calMinDeleTime(string str)
    {
        int N =str.length();
        cout << "N= " << N << endl;
        vector<vector<int>>dp(N+1, vector<int>(N+1, 0));
        for(int len = 1; len <= N; len++){
            for(int start = 0; start < N; start++ ){
                if(len == 1){
                    dp[start][start] = 0;
                    continue;
                }

                int end = start + len -1;
                if(end >= N ) continue;
                cout << "len= " << len << " start= " << start << " end= " << end << endl;

                
                if(str[start] == str[end] && dp[start+1][end-1] == 0){
                    dp[start][end] = 0;
                }else{
                    dp[start][end]= INT32_MAX;
                    for(int k = start; k < end; k++){
                        // cout << "start= " << start << " end= " << end << " k= " << k << " " << dp[start][k] << " " << dp[k+1][end] << endl;
                        cout << " " << dp[start][k] << " " << dp[k+1][end] << endl;
                        int temp = dp[start][k]+ dp[k+1][end] + 1;
                        dp[start][end] = min(dp[start][end], temp);

                    }
                }
                cout << "dp["<< start << "]["<< end << "]= " << dp[start][end] << endl;

            }
        }
        MyPrintTwo(dp);
        cout << "dp=" << dp[0][N-1] << endl;
        
        return 0;
    }
};


void getInputData(string &str)
{
    cin >> str ;
    cout << "input= " << str << endl;

}

int main()
{
    Solution s1;
    string str = "abacaDFADSDASADSASSDAASSDE";
    // getInputData(str);
    int resu = s1.calMinDeleTime(str);
    cout << "end " << endl;
    cout << resu << endl;
    return 0;
}