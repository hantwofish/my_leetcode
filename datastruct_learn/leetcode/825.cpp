#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include "../TREE.h"


using namespace std;


class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int resu = 0;
        sort(ages.begin(),ages.end());
        for(int i = 0; i < ages.size(); i++){
            for(int j = i +1; j < ages.size(); j++){
                if(isFriend(ages,  i,j)){
                    resu++;
                }
                if(isFriend(ages, j,i)){
                    resu++;
                }
            }
        }
        cout << "resu= " << resu << endl;
        return resu;
        
    }
    bool isFriend(vector<int>&ages, int x , int y)
    {
        if(ages[y] <= 0.5 * ages[x] + 7 ){
            return false;
        }
        if(ages[y] > ages[x]){
            return false;
        }
        if(ages[y] > 100 && ages[x] < 100){
            return false;
        }
        return true;
    }
};


int main()
{
    Solution s1;
    vector<int>ages = {20,30,100,110,120};
    s1.numFriendRequests(ages);
   cout << "[info] main end" << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe