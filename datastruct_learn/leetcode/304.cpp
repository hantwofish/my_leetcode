#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>

#define TIMEINTERVAL 6

using namespace std;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << "timer " <<  seconds << " is over exit " << endl;
    exit(1);
}


// 二维数组前缀和
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        data.resize(N, vector<int>(M,0));
        data[0][0] =  matrix[0][0];
        for(int j =1 ; j < M; j++){
            data[0][j] = data[0][j-1] + matrix[0][j];
        }
        for(int i = 1; i< N; i++){
            data[i][0] = data[i-1][0] + matrix[i][0];
        }
        for(int i = 1; i < N; i++){
            for(int j = 1; j < M; j++){
                data[i][j] = data[i-1][j] + data[i][j-1] - data[i-1][j-1] + matrix[i][j];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && row2 == 0 && col1 == 0 && col2 == 0){
            return data[0][0];
        }
        int resu = 0;
        int dat1 = 0;
        int dat2 = 0;
        int dat3 = 0;
        if(col1 >= 1){
            dat1 = data[row2][col1 -1];
        }
        if(row1 >= 1){
            dat2 = data[row1 -1][col2];
        }
        if(row1 >= 1 && col1 >= 1){
            dat3 = data[row1-1][col1-1];
        }
        // resu = data[row2][col2] - data[row2][col1 -1] - data[row1 -1][col2] + data[row1-1][col1-1];
        resu = data[row2][col2] - dat1 -  dat2 + dat3 ;

        return resu;
    }
private:
    vector<vector<int>>data; // data[i][j] 为 [0][0] -> [i][j] 的和
};

int mainFunc()
{
   vector<vector<int>> matrix= {{{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}}};
    NumMatrix s1(matrix);
    int resu = s1.sumRegion(0,0,0,0);
    cout << "resu= " << resu << endl;
    return 0;
}

int main()
{
    std::cout << "Starting timer for " << TIMEINTERVAL << " seconds" << std::endl;
    std::thread timer_thread(timer_function, TIMEINTERVAL); // 设置计时器延时 TIMEINTERVAL 秒

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "main end" << endl;
        return 0;
    }

    timer_thread.join(); // 等待计时器线程完成
    std::cout << "Timer thread finished" << std::endl;
    return 0;
}