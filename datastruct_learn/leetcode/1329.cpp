#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>

#define TIMEINTERVAL 6

using namespace std;



int main()
{


vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};



map< vector<int>, string > mymaaa;
vector<int>tem({1,2,3});
mymaaa.insert({tem, "sss"});
cout << mymaaa[tem] << endl;
cout << mymaaa.size() << endl;

cout << "end " << endl;
    return 0;
}