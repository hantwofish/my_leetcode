#include"../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<set>
#include<unordered_set>

#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>
#include <iterator>

using namespace std;

class Solution {
public:
    int countDigits(int num) {
        string str = to_string(num);
        cout << "str= " << str << endl;
        int resu = 0;
        for(int i = 0; i< str.size(); i++){
            if(str[i] == '0'){
                continue;
            }
            if(num % (str[i] - '0') == 0){
                resu++;
            }
        }
        cout << resu <<endl;
        return resu;
        
    }
};



int main()
{
    Solution s1;
    s1.countDigits(110);
    

    cout << "hello" << endl;
    return 0;
}