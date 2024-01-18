#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M =matrix[0].size();
        vector<vector<int>>dp(N,vector<int>(M,0));
        dp[0] = matrix[0];
        for(int i = 1; i < N; i++){
            for(int j= 0; j< M; j++){
                int case1 ,case2, case3;
                case1 = case2 = case3 = INT32_MAX;
                if(indexIsVaild(matrix, i-1, j-1)) case1 = dp[i-1][j-1];
                if(indexIsVaild(matrix, i-1, j)) case2 = dp[i-1][j];
                if(indexIsVaild(matrix, i-1, j+1)) case3 = dp[i-1][j+1];
                dp[i][j] = min(case1,min(case2,case3) ) + matrix[i][j];

            }
        }
        // MyPrintTwo(dp);
        vector<int>temp = dp[N-1];
        int resu = dp[N-1][0];
        for(int i = 0; i< M; i++){
            resu = min(resu,dp[N-1][i]);
        }
        return resu;
    }
private:
    bool indexIsVaild(vector<vector<int>>& matrix, int i, int j)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if(i >=0 && i <n && j>=0 && j < m){
            return true;
        }
        return false;
    }

};

int main()
{
    Solution s1;
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    s1.minFallingPathSum(matrix);

    

    cout << "hell22o" << endl;
    return 0;
}