#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        unordered_set<int>myset;
        for(int i = 0; i < nums.size(); i++){
            for(int j = -1*k ; j <= k; j++){
                myset.insert(nums[i]+j);
            }
        }
        for (auto it= myset.begin(); it != myset.end() ;it++){
           cout << *it << " ";
        }
        cout << endl;
        return min(myset.size(), nums.size());
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