#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int val = nums[i];
            get_4_map(val);
        }
        int resu = 0;

        for(int i = 0; i < nums.size(); i++){
            int val = nums[i];
            set<int>temp = my_Mp[val];

            // cout << "val = " << val << endl;
            // for(int j = 0; j < temp.size(); j++){
            //     cout << " " <<  temp[j];
            // }
            // cout << "  xxxx " << endl;


            if(temp.size() == 4){
                for(auto j = temp.begin(); j != temp.end(); j++){
                    resu += *j;
                    cout << " " <<  *j;
                }
                cout << endl;
            }
            

        }
        cout << "resu= " << resu << endl;
        return resu;
    }
    void get_4_map(int val)
    {
        if(my_Mp.find(val) != my_Mp.end()){
            return;
        }
        // cout << "val= " << val << endl;
        for(int i = 1; i <= sqrt(val) ; i++){
            if( val % i == 0){
                cout << "val= " << val <<  " i= " << i <<  " val/i " << val /i << endl;
                my_Mp[val].insert(i);
                my_Mp[val].insert(val /i);
            }
        }
    }
private:
    unordered_map<int, set<int>> my_Mp;
};

int main()
{
    // vector<int>nums= {21,21};
    vector<int>nums= {21,4,7};
    Solution s1;
    s1.sumFourDivisors(nums);

   cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe