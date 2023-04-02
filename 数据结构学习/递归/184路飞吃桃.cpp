#include"../../STLCOMMON.h"
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// #include<set>
// #include<unordered_set>
// #include<unordered_map>
// #include<stack>
using namespace std;


class Solution{
public:
    int getN(int N)
    {
        g_M = N;
        return func(1);

    }
    int func(int n)
    {
        if(n == g_M){
            return 1;
        }

        return 2*(func(n+ 1)+1);
    }
public:
    int g_M;

};

int main()
{
    Solution s1;
    int N;
    cin >> N;
    cout << s1.getN(N) << endl;
    cout << "end" << endl;
}