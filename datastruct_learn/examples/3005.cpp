

#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
 
        for(int i = 0;i < nums.size(); i++){
            vec_map[nums[i]]++;
        }
        int max_times = 0;
        auto it = vec_map.begin();
        while (it != vec_map.end())
        {
            max_times= max(max_times, it->second);
            it++;
        }

        int resu = 0;
        it = vec_map.begin();
        while (it != vec_map.end())
        {
           if( it->second == max_times){
                resu += max_times; 
           }
            it++;
        }
        return resu;
        
    }
private:
    unordered_map<int,int> vec_map;
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