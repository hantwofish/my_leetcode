#ifndef STLCOMMON_H
#define STLCOMMON_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<stack>

using namespace std;
template<typename T1>
void MyPrintTwo(vector<vector<T1>> &data)
{
    for(int i = 0; i< data.size(); i++){
        for(int j = 0; j < data[i].size(); j++){
            cout<< data[i][j] << " ";
        }
        cout << endl;
    }
}
template<typename T2>
void MyPrintOne(vector<T2> &data)
{
    for(int i = 0; i< data.size(); i++){
        cout<< data[i] << " ";
    }
    cout << endl;
}
#endif