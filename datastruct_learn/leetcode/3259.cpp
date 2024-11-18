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
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        if(n == 1){
            return max(energyDrinkA[0], energyDrinkB[1]);
        }else if(n ==2){
            return max(energyDrinkA[0]+ energyDrinkA[1], energyDrinkB[0]+energyDrinkB[1]);
        }
        vector<vector<long long>>dp(n, vector<long long>(2,0));
        cout << "XXX n=  " << n << endl;
        for(int i = 0; i < n; i++){
            cout << "i= " << i << endl;
            if(i == 0){
                dp[i][0] = energyDrinkA[i];
                dp[i][1] = energyDrinkB[i];
                // cout << "A :" << " push A " << i << endl;
                // cout << "B :" << " push B " << i << endl;
            }else if(i ==1){
                dp[i][0] = dp[i-1][0] + energyDrinkA[i];
                dp[i][1] = dp[i-1][1] + energyDrinkB[i];
                // cout << "A :" << " push A " << i << endl;
                // cout << "B :" << " push B " << i << endl;
            }else{
                dp[i][0] = max(dp[i-1][0], dp[i-2][1]) + energyDrinkA[i];
                dp[i][1] = max(dp[i-1][1], dp[i-2][0]) + energyDrinkB[i];
                if(dp[i-1][0] < dp[i-2][1]){
                    cout << "A :" << " push B " << i-2 << endl;
                }else{
                    cout << "A :" << " push A " << i-1 << endl;
                }

                if(dp[i-1][1] < dp[i-2][0]){
                    cout << "B :" << " push B " << i-2 << endl;
                }else{
                    cout << "B :" << " push A " << i-1 << endl;
                }


            }            
        }
        if(dp[n-1][0] < dp[n-1][1]){
            cout << "chose B" << endl;
        }else{
            cout << "chose A" << endl;
        }
        
        cout << "max= " << max(dp[n-1][0], dp[n-1][1]) << endl;



        return max(dp[n-1][0], dp[n-1][1]);
    }
};

int mainFunc()
{
    Solution s1;
    vector<int> energyDrinkA = {4,1,8,3};
    vector<int> energyDrinkB = {1,1,3,5};
    s1.maxEnergyBoost(energyDrinkA,energyDrinkB);

    cout << "end ..." << endl;
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


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe