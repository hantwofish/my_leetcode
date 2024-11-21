#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"


using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row = 0;
        int col = 0;
        for(int i = 0 ; i < commands.size(); i++){
            string temp =  commands[i];
            if(temp == "UP"){
                row--;
            }else if(temp == "RIGHT"){
                col++;
            }else if(temp == "DOWN"){
                row++;
            }else{
                col--;
            }
        }
        return row * n + col;
    }
};

int main()
{

   cout << "[info] main end" << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe