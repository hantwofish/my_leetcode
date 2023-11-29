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
    string reverseWords(string s) {
        // 找到第一个不为空格的字符索引
        int start = 0;
        while (start < s.size() && s[start] == ' ') {
            start++;
        }
        int cur = start;
        while(cur < s.size()){
            int indexSpace = s.find(" ",cur);
            cout << "index= " << indexSpace << " " << string::npos<< endl;
            if(indexSpace== -1){
                cout << "break str= " << s.substr(cur) << endl;
                myVec.push_back(s.substr(cur));
                break;
            }
            // if(indexSpace < 0 || indexSpace ==string::npos){
            //     break;
            // }

            string str = s.substr(cur, indexSpace-cur+1 - 1);
            cout << "str= " << str << endl;
            myVec.push_back(str);
            cur = indexSpace;
            while (cur < s.size() && s[cur] == ' ') {
                cur++;
            }
        }
        string resu ="";
        reverse(myVec.begin(),myVec.end());
        for(int i = 0; i< myVec.size()-1; i++){
            resu = resu + myVec[i] + " ";
        }
        resu += myVec[myVec.size()-1];
        
        return resu;
    }
public:
    vector<string>myVec;
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    string str = "the sky is blue";
    string str1 = "  hello world  ";
    string str2 = "a good   example";
    string resu = s1.reverseWords(str2);
    cout << resu << endl;
    

    // cout << "hello" << endl;
    return 0;
}
