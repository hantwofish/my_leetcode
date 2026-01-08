#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        for(int j = 0; j < N; j++){
            int ord_flag = 0;
            if( (0 + j ) % 2 == 1){
                ord_flag =1;
            }
            int start_row = 0;
            int start_col = j;
            nums.clear();
            if( ord_flag == 0){ // 偶数斜列
                while( start_row < M && start_col >= 0 ){

                    cout << mat[start_row][start_col] << " ";
                    nums.push_back(mat[start_row][start_col]);
                    start_row++;
                    start_col--;
                }
                reverse(nums.begin(), nums.end());

            }else{ // 奇数斜列
                while( start_row < M && start_col >= 0 ){

                    cout << mat[start_row][start_col] << " ";
                    nums.push_back(mat[start_row][start_col]);
                    start_row++;
                    start_col--;
                }
                

            }
            for(auto id : nums){
                result.push_back(id);
            }
        }


        for(int i = 1; i < M; i++){
            int start_row = i;
            int start_col = N-1;
            int ord_flag = 0;
            if( (start_row + start_col ) % 2 == 1){
                ord_flag =1;
            }
            nums.clear();
            if( ord_flag == 0){ // 偶数斜列
                while( start_row < M && start_col >= 0 ){

                    cout << mat[start_row][start_col] << " ";
                    nums.push_back(mat[start_row][start_col]);
                    start_row++;
                    start_col--;
                }
                reverse(nums.begin(), nums.end());

            }else{ // 奇数斜列
                while( start_row < M && start_col >= 0 ){

                    cout << mat[start_row][start_col] << " ";
                    nums.push_back(mat[start_row][start_col]);
                    start_row++;
                    start_col--;
                }
                

            }
            for(auto id : nums){
                result.push_back(id);
            }
        }

        cout << endl;
        MyPrintOne(result);
        return result;
    }
private:
    vector<int>nums;
    vector<int>result;
};


int main()
{
    vector<vector<int>>nums = {
{1,2,3},{4,5,6},{7,8,9}
                                };
Solution s1;
s1.findDiagonalOrder(nums);

   cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe