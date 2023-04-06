#include"../STLCOMMON.h"

using namespace std;

/*
set 不可包含重复元素，自动排序
*/

set<pair<int,int>>g_mySet;

void PrintSet(set<pair<int,int>>&mySet)
{
    cout << "-----------start------------"<< endl;
    auto it = mySet.begin();
    while (it != mySet.end()){
        cout << it->first << " " << it ->second << endl;
        it++;
    }  
    cout << "-----------start------------" << endl;

}

void test()
{
    for(int i = 0; i< 10; i++){
        g_mySet.insert({rand()%10, i});
    }
    auto it = g_mySet.begin();
    PrintSet(g_mySet);



    // 查找：
    it = g_mySet.find({1,1});
    if(it != g_mySet.end()){
        cout << "found" << endl;
    }else{
        cout << "NOT found" << endl;
    }
    g_mySet.insert({15, 16});
    PrintSet(g_mySet);
    g_mySet.erase({15,16});
    g_mySet.erase(g_mySet.begin());
    PrintSet(g_mySet);
}

int main()
{
    test();
    return 0;
}