#include"../STLCOMMON.h"
#include"../COMMONALO.h"
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
    int nextBeautifulNumber(int n) {
        for(int i = n+ 1; i < INT32_MAX; i++){
            if(isVaild(i)) return i;
        }
        return -1;
    }
    bool isVaild(int n)
    {
        string str = to_string(n);
        unordered_map<char, int>mymap;
        for(int i= 0; i< str.size();i++){
            mymap[str[i]]++;
        }
        auto it= mymap.begin();
        while(it != mymap.end()){
            if(it->first - '0' != it->second) return false;
            it++;
        }
        return true;
    }
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}