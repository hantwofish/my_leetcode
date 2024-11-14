#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;




class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        N = points.size();
        figure.resize(N, vector<int>(N, 0));
        for(int i = 0; i< points.size(); i++){
            for(int j = i+1; j < points.size(); j++){   
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                figure[i][j] = dist;
                figure[j][i] = dist;
            }
        }
        MyPrintTwo(figure);

        int outVal = INT32_MAX;

        for(int i = 0; i < N; i++){
            int resu = getValDelete(i);
            cout << "resu = " << resu << endl;
            outVal = min(outVal, resu);
        }
        cout << "outVal= " << outVal << endl;
        return outVal;

    }
    int getValDelete(int deleNum)
    {
        int resu = -1;
        for(int i = 0 ; i< N; i++){
            if(i == deleNum) continue;
            for(int j = i+ 1; j < N; j++){
                if(j == deleNum) continue;
                resu = max(resu, figure[i][j]);
            }
        }
        return resu;
    }
private:
    int N;
    vector<vector<int>>figure;
};



int mainFunc()
{
    Solution s1;
    vector<vector<int>> points = {{3,10},{5,15},{10,2},{4,4}};
    s1.minimumDistance(points);

    return 0;
}

int main()
{

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}