#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"


using namespace std;

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int resu = 0;
        for(int i = l; i <= r; i++){
            if(i == 1 || i == 2) continue;
            int n =  sqrt(i);
            if(n*n == i && isPrime(n)){
                cout << "i= " << i << " n = " << n << endl;
                resu++;
            }   
        }

        return  r- l+1 - resu;
        
    }
    bool isPrime(int num)
    {
        if(num == 2) return true;
        int half_num = sqrt(num);
        for(int i = 2; i <= half_num + 1; i++){
            if(num % i == 0) return false;
        }
        return true;
    }
};

int main()
{
    Solution s1;
    int l = 400;
    int r = 1000;
    int resu = s1.nonSpecialCount(l,r);
    cout << "resu= " << resu << endl;
    cout << "[info] main end" << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe