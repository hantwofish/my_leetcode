#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"


using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int M =11;
        vector<vector<int>>data(n, vector<int>(M,0));
        for(int i = 0; i< pick.size(); i++){
            int x =  pick[i][0];
            int y =  pick[i][1];
            data[x][y]++;
        }
        int resu = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j< M; j++){
                if(data[i][j] > i){
                    resu++;
                    break;
                }
            }
        }
        cout << "resu= " << resu << endl;
        return resu;
    }
};

int main()
{

    int n = 4;
    vector<vector<int>> pick = {{0,0},{1,0},{1,0},{2,1},{2,1},{2,0}};
    Solution s1;
    s1.winningPlayerCount(n,pick);

   cout << "[info] main end" << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe