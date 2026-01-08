#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums ;
        for(int i = 0 ; i< m;i++){
            nums.push_back(nums1[i]);
        }
        for(int j = 0 ; j< n;j++){
            nums.push_back(nums2[j]);
        }
        sort(nums.begin(), nums.end());
        nums1 = nums;
        return;
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