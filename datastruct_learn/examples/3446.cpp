#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        MyPrintTwo(grid);
        int M= grid.size();
        

        result.clear();
        result.resize(M,vector<int>(M,0));
        

        // 右上
        for(int j = 1; j < M; j++ ){
            const  int start_row=0;
            const  int start_col=j;

            int cur_row =0 ;
            int cur_col = j;
            vector<int>tmp_nums;
            while (cur_row <M && cur_col <M) {
                tmp_nums.push_back(grid[cur_row][cur_col]);
                cur_row++;
                cur_col++;
                
            }
            MyPrintOne(tmp_nums);
            sort(tmp_nums.begin(), tmp_nums.end());

            int cur_index=0;
            cur_row =start_row;
            cur_col = start_col;
            while (cur_row <M && cur_col <M) {
                // tmp_nums.push_back(grid[cur_row][cur_col]);
                result[cur_row][cur_col] = tmp_nums[cur_index];
                cur_row++;
                cur_col++;
                cur_index++;
            }

        }


        // 左下
        for(int i = 0; i < M; i++ ){
            const  int start_row=i;
            const  int start_col=0;

            int cur_row = start_row ;
            int cur_col = start_col;
            vector<int>tmp_nums;
            while (cur_row <M && cur_col <M) {
                tmp_nums.push_back(grid[cur_row][cur_col]);
                cur_row++;
                cur_col++;
                
            }
            MyPrintOne(tmp_nums);
            sort(tmp_nums.begin(), tmp_nums.end());
            

            int cur_index= tmp_nums.size()-1;
            cur_row =start_row;
            cur_col = start_col;
            while (cur_row <M && cur_col <M) {
                // tmp_nums.push_back(grid[cur_row][cur_col]);
                result[cur_row][cur_col] = tmp_nums[cur_index];
                cur_row++;
                cur_col++;
                cur_index--;
            }

        }  

        MyPrintTwo(result);

        return result;
        
    }
private:
    vector<vector<int>>result;
};


int main()
{
    Solution S1;
    vector<vector<int>> grid= {{1,7,3},{9,8,2},{4,5,6}};
    S1.sortMatrix(grid);

   cout << "[info:] main end ..." << endl << endl;

    return 0;
}
