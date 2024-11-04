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
    int minChanges(int n, int k) {
       string numsa = intTo2str(0, n);
       string numsb = intTo2str(0, k);
       int N = max(numsa.length(), numsb.length());
        for(int i = 0; i < N - numsa.length(); i++){
            numsa = "0" + numsa;
        }
        for(int i = 0; i < N - numsb.length(); i++){
            numsb = "0" + numsb;
        }
        cout << "a= " << numsa << endl;
        cout << "b= " << numsb << endl;
        int times = 0;
        for(int i = 0; i < N; i++){
            if(numsa[i] != numsb[i] && numsa[i] == '1'){
                numsa[i] = '0';
                times++;
            }
        }
        if(numsa == numsb){
            return times;
        }
       return -1;
    }   
private: // 二进制 转字符  nums 为待转的数字，N 为总位数，不够的前面补0
    string intTo2str(const int N, int nums){
        string resu = "";
        while(nums){
            int yu = nums %2;
            nums = nums / 2;
            // cout << yu << " ";
            resu = to_string(yu) + resu;
        }
        // cout << "resu= " << resu << endl;
        // int lenSize = resu.size();
        // for(int i = 0; i < N - lenSize; i++){
        //     resu = "0" + resu;
        // }
        cout << "num= " << nums << "  resu= " << resu << endl;
        return resu;
    }
};

int mainFunc()
{
    Solution s1;
    int n = 13; 
    int k = 4;
    s1.minChanges(n,k);

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