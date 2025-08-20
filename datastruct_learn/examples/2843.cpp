#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;


class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int result = 0;
        cout << "start  " << endl;
        for(int num = low; num <= high ; num++){
            string num_Str = to_string(num);
            // cout << num_Str << "  " << endl; 

            if(num_Str.length() %2 == 1){
                continue;
            }
            long long  front_sum = 0;
            long long  behind_sum = 0;
            for(int i = 0; i < num_Str.length()/2; i++){
                front_sum += (num_Str[i]- '0');

            }
            for(int j = num_Str.length()/2 ; j < num_Str.length(); j++){
                behind_sum += (num_Str[j]- '0');
            }
            if(front_sum == behind_sum){
                result++;
            }
            
        }
        cout << "result= " << result << endl;
        return result;
    }
};


int main()
{
    Solution s1;
    int low =1;
    int high = 100;
    s1.countSymmetricIntegers(low, high);

   cout << "[info] main end ..." << endl << endl;

    return 0;
}