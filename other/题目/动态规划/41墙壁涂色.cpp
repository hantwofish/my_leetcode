#include"../../STLCOMMON.h"
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

class Solution2{ // 采用回溯的方式,超时
public:
    int CalTimes(int n, int k)
    {
        space.resize(n,0);
        coloarNum =k;
        spaceNum =n;
        DFS(0,0,spaceNum-1);

        return resu;
    }
    void DFS(int start, int cur, int end)
    {
        if(cur > end) {
            resu++;
            // cout << "resu= " << resu << endl;
            // MyPrintOne(space);
            return;
        }
        for(int i = 1; i<= coloarNum; i++ ){
            // 如果放置的元素不合法，直接continue
            if(  ((cur != 0 ) && (i ==  space[cur-1])) || ((cur == spaceNum-1)&& (i == space[0]))  ){
                continue;
            }
            space[cur] = i;
            DFS(start, cur+1, end);
            space[cur] = 0;
        }
        
    }

public:
    int resu = 0;
    int coloarNum;
    int spaceNum;
    vector<int>space;
};

class Solution{ // 采用回溯的方式,超时
public:
    int CalTimes(int n, int k)
    {
        spaceNum =n;
        colorNum =k;

        fdata.resize(spaceNum,vector<vector<int>>(colorNum, vector<int>(colorNum,0)));

        return 0;
    }
    

public:
    int resu = 0;
    int spaceNum ;
    int colorNum;
    vector<vector<vector<int>>>fdata;
};
int main()
{
    Solution s1;
    int n = 20;
    int k =4;
    // cin >> n >> k;
    int resu = s1.CalTimes(n,k);
    cout  << resu << endl;
    return 0;
}