#include"../STLCOMMON.h"
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // 计算前缀和
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> frontSum(row+1, vector<int>(col+1,0));
        for(int i = 0; i< row; i++){
            for(int j = 0; j < col; j++){
                frontSum[i+1][j+1] = 
                    frontSum[i][j+1] + frontSum[i+1][j] - frontSum[i][j] + matrix[i][j] ; 
            }
        }
        MyPrintTwo(frontSum);
        // 暴力循环 超时
        int sumRowMax = frontSum.size();
        int sumColMax = frontSum[0].size();
        int resu = INT32_MIN;
        for(int i = 1; i< sumRowMax ; i++){
            for(int j = 1; j < sumColMax; j++){
                for(int m = i; m < sumRowMax; m++){
                    for(int n = j; n < sumColMax ; n++){
                        int arr1 = frontSum[i-1][j-1];
                        int arr2 = frontSum[i-1][n] - arr1;
                        int arr3 = frontSum[m][j-1] - arr1;
                        int arr4 = frontSum[m][n] - arr1 -arr2 - arr3;
                        cout << i << " " << j << " " << m << " " 
                             << n << " " << "arr4= " << arr4 << endl;
                        if(arr4 <= k){
                            resu = max(resu, arr4);
                        }

                    }
                }
            }
        }


        return resu;
    }
};



int main()
{ 
    Solution s1;
    vector<vector<int>>matrix = {{1,0,1},{0,-2,3}};
    //vector<vector<int>>matrix = {{2,2,-1}};
    int  k = 2;
    int resu = s1.maxSumSubmatrix(matrix, k);
    cout << "main resu= " << resu << endl;
    return 0;
}