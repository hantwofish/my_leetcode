// #include"../STLCOMMON.h"
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
    int calMaxArray(string &str1, string &str2)
    {
        str1 = "0"+str1;
        str2 = "0"+str2;
        int N =str1.size();
        int M =str2.size();
        vector<vector<int>>dp(N+1, vector<int>(M+1,0));

        for(int i = 1; i< N; i++){
            for(int j =1 ;j < M; j++){
                int temp1 = dp[i-1][j];
                int temp2 = dp[i][j-1];
                int temp3 = dp[i-1][j-1] + (str1[i] == str2[j]);

                dp[i][j] = max(temp1, max(temp2, temp3));
            }
        }

        // MyPrintTwo(dp);

        
        return dp[N-1][M-1];
    }
};

void getIndata(string &a, string &b)
{
    cin >> a >>b;
}



int main()
{
    Solution s1;
    string a = "sehuaiexi";
    string b = "yhaizeyiux";
    getIndata(a,b);
    int resu = s1.calMaxArray(a,b);
    cout << resu << endl;

    return 0;
}

