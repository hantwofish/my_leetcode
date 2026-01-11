#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>vec;
        int N1= nums1.size();
        int N2= nums2.size();
        int k1 = min(k ,N1);
        int k2 = min(k, N2);

        for(int i = 0; i < k1; i++){
            for(int j = 0; j < k2;j++){
                vec.push_back({nums1[i],nums2[j]});
            }
        }
        vec_Sort_pair(vec);

        k1 = min(k, (int)vec.size());
        vector<vector<int>>resul;
        for(int i = 0; i< k1; i++){
            resul.push_back({vec[i].first, vec[i].second});
        }


        
        return resul;
    }
    void vec_Sort_pair(vector<pair<int,int>>&nums)
    {
        int N = nums.size();
        // int temp = 0;
        for(int i = 0; i< N; i++){
            for(int j = 0; j <N -1; j++){
                if(nums[j].first + nums[j].second  > nums[j+1].first + nums[j+1].second){
                    auto temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] =temp;
                }
            }
        }
        // MyPrintOne_simple(nums);
    }

    void vec_Sort(vector<int>&nums)
    {
        // MyPrintOne_simple(nums);
        int N = nums.size();
        int temp = 0;
        for(int i = 0; i< N; i++){
            for(int j = 0; j <N -1; j++){
                if(nums[j] > nums[j+1]){
                    temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] =temp;
                }
            }
        }
        // MyPrintOne_simple(nums);
    }
    
};

int main()
{
    Solution s1;
    vector<int>nums;
    for(int i = 0; i < 10; i++){
        nums.push_back(rand() % 25);
    }
    s1.vec_Sort(nums);

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp