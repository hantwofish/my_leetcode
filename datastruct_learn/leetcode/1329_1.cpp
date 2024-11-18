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


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        N = mat.size();
        M = mat[0].size();
        cout << "N= " << N << " M= " << M <<endl;
        for(int j = 0; j< M; j++ ){
            cout << "j= " << j << endl;
            getVec(mat, 0, j);
        }

        for(int i = 1; i< N; i++ ){
            cout << "i= " << i << endl;
            getVec(mat, i, 0);
        }

        sorMap();
        for(int j = 0; j< M; j++ ){
            cout << "j= " << j << endl;
            setVec(mat, 0, j);
        }

        for(int i = 1; i< N; i++ ){
            cout << "i= " << i << endl;
            setVec(mat, i, 0);
        }

        MyPrintTwo(mat);
        return mat;
    }
    void sorMap()
    {
        auto it = myMap.begin();
        while(it != myMap.end()){
            sort(it->second.begin(), it->second.end());
            it++;
        }

    }
    void getVec(vector<vector<int>>& mat, int i, int j)
    {
        int cur_i = i;
        int cur_j = j;
        while(cur_i < N && cur_j < M){
            myMap[{i, j}].push_back(mat[cur_i][cur_j]);
            cur_i++;
            cur_j++;
        }
    }

    void setVec(vector<vector<int>>& mat, int i, int j)
    {
        int cur_i = i;
        int cur_j = j;
        vector<int>vec = myMap[{i, j}];
        int index = 0;
        while(cur_i < N && cur_j < M){
            mat[cur_i][cur_j] = vec[index];
            index++;
            cur_i++;
            cur_j++;
        }
    }
private:
    map<pair<int, int>, vector<int>>myMap;
    int N;
    int M;
};

// unordered_map可以使用基本类型(int等)，string作为key，不能使用pair vector作为key，map可以使用基本类型，string和pair vector作为key。





int mainFunc()
{
    Solution s1;
    vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};

    s1.diagonalSort(mat);
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