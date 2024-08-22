#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;



/*
将 n-1 x 转成二进制，
将 n-1 的二进制，填充到 x 二进制的0 的位置

*/
class Solution {
public:
    long long minEnd(int n, int x) {
        string str_n = numtobin(n -1);
        string str_x = numtobin(x);
        string resu;
        int MAX_LEN = 64;
        resu.resize(MAX_LEN, '0');
        
        int i = MAX_LEN -1;

        for(int j = str_x.size() -1; j >= 0; j--){
            resu[i] = str_x[j];
            i--;
        }
        cout << "1 resu = " << resu << endl;
        i = MAX_LEN -1;
        for(int j = str_n.size()-1; j >= 0; j--){
            while(resu[i] != '0'){
                i--;
            }
            resu[i] = str_n[j];
            i--;
        }
        cout << "2 resu = " << resu << endl;

        long long resu_num = 0;
        for(int i = MAX_LEN -1; i >= 0; i--){
            if(resu[i] == '0'){
                continue;
            }
            resu_num = resu_num + (long long)pow(2, MAX_LEN -1 - i);
        }
        cout << resu_num << endl;

        return resu_num;
    }
    string numtobin(int num)
    {
        string resu = "";
        while (num > 0) {
            resu += to_string(num % 2);
            num /= 2;
        }
        reverse(resu.begin(), resu.end());
        cout << resu << endl;
        return resu;
    }
};

int mainFunc()
{
    Solution s1;
    // s1.numtobin(10);
    int n = 2;
    int x = 7;
    s1.minEnd(n,x);

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