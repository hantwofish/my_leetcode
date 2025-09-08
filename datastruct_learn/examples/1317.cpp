#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {

        for(int i= 1; i < n; i++){
            int j = n-i;
            if(!isContainedZero(i) && !isContainedZero(j)){
                return {i,j};
            }

        }
        return {0,0};
    }
private:
    bool isContainedZero(int num)
    {
        string str = to_string(num);
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '0'){
                return true;
            }
        }
        return false;
    }
};

int main()
{

   cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe