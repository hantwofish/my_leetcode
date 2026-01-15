#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int>my_map;
        int index= 0;
        for(int i = 0; i< strs.size(); i++){
            string temp =  strs[i];
            sort(temp.begin(), temp.end());
            if(my_map.find(temp) == my_map.end()){
                my_map[temp] = index;
                index++;
            }
            
        }
        cout << "Index= " << index << endl;
        vector<vector<string>>result;
        result.resize(index );
        for(int i = 0; i< strs.size(); i++){
            string temp =  strs[i];
            sort(temp.begin(), temp.end());
            int location = my_map[temp];
            cout << "location ="  << location << endl;
            result[location].push_back(strs[i]);
        }
        return result;
    }
};

int main()
{

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s1;
    s1.groupAnagrams(strs);
    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp