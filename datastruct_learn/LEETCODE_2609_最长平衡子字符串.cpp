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
    int findTheLongestBalancedSubstring(string s) {
        int N = s.length();
        int resu = 0;
        for(int i =0; i< N; i++){
            if(s[i] != '0') continue;
            int start = i;
            int begind = i +1;
            int zeroNum = 0;
            int oneNum = 0;
            for(int j = start; j < N; j++){
                if(s[j] == '0') zeroNum++;
                if(s[j] == '1') oneNum++;


            }
        }
        
    }
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    

    cout << "hello" << endl;
    return 0;
}