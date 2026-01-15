#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int>map1;
        unordered_map<string,int>map2;
        for(int i = 0; i< pattern.size(); i++){
            map1[pattern[i]]++;
        }

        int i =0;
        int j = 0;
        while(i < s.length() && j < s.length()){
            if(s[j] == ' '){
                string temp = s.substr(i, j-i);
                map2[temp]++;
                cout << temp << endl;
                i = j+1;
                j = i;
            }else{
                j++;
            }
            if(j == s.length()){
                string temp = s.substr(i, j-i);
                cout << temp << endl;
                map2[temp]++;
            }
        }
        vector<int>nums1;
        vector<int>nums2;
        auto it = map1.begin();
        while(it != map1.end()){
            nums1.push_back(it->second);
            it++;
        }
        auto it2 = map2.begin();
        while(it2 != map2.end()){
            nums2.push_back(it2->second);
            it2++;
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        return nums1==nums2;
    }
};

int main()
{
    string pattern = "abba";
    string s = "dog cat cat dog";
    Solution s1;
    s1.wordPattern(pattern, s);

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp