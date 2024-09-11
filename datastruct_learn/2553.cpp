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
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>resu;
        for(int i = 0; i < nums.size(); i++){
            string temp = getStr(nums[i]);
            for(int j = 0; j < temp.size(); j++){
                resu.push_back(temp[j] - '0');
            }
        }
        return resu;
        
    }
    string getStr(int num)
    {
        string resu = "";
        while(num){
            char c= num % 10 + ('0'-0);
            resu =   c + resu;
            num /= 10;
        }
        cout << "resu= " << resu << endl;
        return resu;
    }
};

int mainFunc()
{
    Solution s1;
    s1.getStr(135);

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