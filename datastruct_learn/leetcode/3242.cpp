#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;



class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid) {
        N =grid.size();
        numstemp =   grid;
        for(int i = 0; i< N; i++){
            for(int j=0;j < N; j++){
                umap[numstemp[i][j] ] = {i,j};
            }
        }
    }
    
    int adjacentSum(int value) {
        int row = umap[value].first;
        int col =  umap[value].second;
        cout << "adjacentSum row = "<< row << " col = " << col << endl;
        // 上
        int sum = 0;
        if(row-1 >=0 ){
            sum += numstemp[row-1][col];
        }
        if(row +  1 < N){
             sum += numstemp[row+1][col];
        }
        if(col - 1 >=0){
             sum += numstemp[row][col-1];
        }
        if(col + 1 < N){
            sum += numstemp[row][col+1];
        }
        cout << "adjacentSum "<<  " sum = " << sum << endl;
        return sum;
        
    }
    
    int diagonalSum(int value) {
        const int row =  umap[value].first;
        const int col =  umap[value].second;
        cout << "diagonalSum row = "<< row << " col = " << col << endl;
        int sum = 0;
        // 左上
        int row_temp = row -1;
        int col_temp = col -1;
        while(row_temp >=0 && col_temp >= 0){
            sum += numstemp[row_temp][col_temp];
            // cout << "1 val ="  << ((row_temp)* N + col_temp) << endl;
            break;
            row_temp--;
            col_temp--;
        }
        row_temp = (row-1);
        col_temp = (col+1);
        // 右上s
        while(row_temp >=0 && col_temp < N){
            sum +=numstemp[row_temp][col_temp];
            // cout << "2 val ="  << ((row_temp)* N + col_temp) << endl;
            break;
            row_temp--;
            col_temp++;
        }

        row_temp = row+1;
        col_temp = col-1;
        // 左下
        while(row_temp <N && col_temp >= 0){
            sum += numstemp[row_temp][col_temp];
            // cout << "3 val ="  << ((row_temp)* N + col_temp) << endl;
            break;
            row_temp++;
            col_temp--;
        }

        row_temp = row+1;
        col_temp = col+1;
        // 右下
        while(row_temp <N && col_temp <N){
            sum += numstemp[row_temp][col_temp];
            // cout << " 4 val  ="  << ((row_temp)* N + col_temp) << endl;
            break;
            row_temp++;
            col_temp++;
        }
         cout << "          diagonalSum "<<  " sum = " << sum << endl;
        return sum;
    }
private:
    int N;
    vector<vector<int>>numstemp;
    unordered_map<int, pair<int,int>>umap;
    pair<int,int> get_row_col(int num)
    {
        int row = num / N;
        int col = num % N;
        return make_pair(row, col);
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

int mainFunc()
{
    vector<vector<int>>temp(3, vector<int>(3, 0));
    NeighborSum s1(temp);
    s1.adjacentSum(1);
    s1.adjacentSum(4);
    s1.diagonalSum(4);
    s1.diagonalSum(8);

    return 0;
}

int main()
{
    cout << " xxx" <<endl;

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe