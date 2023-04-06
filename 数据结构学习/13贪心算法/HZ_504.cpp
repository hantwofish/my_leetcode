// #include"../../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>


using namespace std;


string GetMinNum(string &n, int s)
{
    int times = s;
    while (times > 0)
    {
        // cout << "times= " << times << endl;
        int N =n.size();
        // cout << "size= " << n.size() << " length= " << n.length() << endl;
        string stashStr  = n;  // 原始字符串
        string actalUsed = n;
        string oneCicle = actalUsed.erase(0,1); // 这一圈下来最小的值
        actalUsed= n;

        for(int i = 0;i < actalUsed.length() ; i++){
            string temp = actalUsed.erase(i,1);
            if( temp <  oneCicle){
                oneCicle = temp; 
            }
            actalUsed = n;
        }
        n = oneCicle;
        times--;
    }

    // 去除 开头的0
    while((!n.empty()) &&  n.front() == '0'){
        n.erase(0, 1);
    }
    
    return n;
}

void GetNum(string &n ,int &s)
{
    cin>> n >> s;
}

int main()
{
    string n = "903071";
    int s = 3;
    GetNum(n, s);
    string resu = GetMinNum(n, s);
    cout  << resu << endl;
    // cout << stoi(resu) << endl;
    // cout << "--end---" << endl;
    return 0;
}