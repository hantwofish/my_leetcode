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

// 两个字符串出现的字符集 s1 s2相等，即 S1=S2
// 分别将两个字符串的字符出现次数数组 f1 , f2进行排序后，两个数组从小到大一一相等
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        for(int i = 0; i < word1.size(); i++){
            char temp = word1[i];
            s1.insert(temp);
            mp1[temp]++;
        }
        for(int i = 0; i < word2.size(); i++){
            char temp = word2[i];
            s2.insert(temp);
            mp2[temp]++;
        }
        vector<int>v1, v2;
        auto it = mp1.begin();
        while(it != mp1.end()){
            v1.push_back(it->second);
            it++;
        }
        while(it != mp2.end()){
            v2.push_back(it->second);
            it++;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        cout << " " <<( s1==s2) << endl;
        cout << " " <<( v1==v2) << endl;
        if(s1==s2 && v1==v2){
            return true;
        }
        return false;

    }
public:
    set<int>s1;
    set<int>s2;
    unordered_map<char,int>mp1;
    unordered_map<char, int>mp2;
};

int main()
{
    Solution s1;
    

    cout << "hello" << endl;
    return 0;
}