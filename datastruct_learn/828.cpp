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

class Solution{
public:
    int uniqueLetterString(string str) {
        int resu = 0;
        for(int start = 0; start < str.length(); start++){
            for(int length = 1; length <= str.length()- start; length++){
                // int endindex = start + length -1;
                string temp = str.substr(start, length);
                resu += calSigStr(temp);
            }
        }
        return resu;
    }
    int calSigStr(string &str)
    {
        int num[26] = {0};
        for(int i = 0; i < str.size(); i++){
            num[str[i]-'A']++;
        }
        int resu = 0;
        for(int i = 0; i< 26; i++){
            if(num[i] ==1){
                resu++;
            }
        }
        return resu;
    }
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    string str="abcd";
    for(int start = 0; start < str.length(); start++){
        for(int length = 1; length <= str.length()- start; length++){
            int endindex = start + length -1;
            cout << str.substr(start, length) << " " << "endindex= " << endindex << endl;
        }
    }

    cout << "hello" << endl;
    return 0;
}