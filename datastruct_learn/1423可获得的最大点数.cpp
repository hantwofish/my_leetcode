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
    int maxScore(vector<int>& cardPoints, int k) {
        int N = cardPoints.size();
        isVisited.resize(N, false);
        getOnePro(cardPoints,0, N-1, k);
        return resu;
    }
    void getOnePro(vector<int>& cardPoints, int begin, int end, int remainNum)
    {
        if(remainNum <= 0){
            // cout << "tempresu= " << tempresu << endl;
            resu = max(resu, tempresu);
            return;
        }  
        
        // 处理 begin
        tempresu += cardPoints[begin];
        isVisited[begin] = true;
        getOnePro(cardPoints,begin+1, end, remainNum-1);
        tempresu -= cardPoints[begin];
        isVisited[begin] = false;

        // 处理 end
        tempresu += cardPoints[end];
        isVisited[end] = true;
        getOnePro(cardPoints,begin, end -1, remainNum-1);
        tempresu -= cardPoints[end];
        isVisited[end] = false;        
    }
public:
    int tempresu = 0;
    int resu = INT32_MIN;
    vector<bool>isVisited;
};

int main()
{
    Solution s1;
    vector<int>cardPoints = {9,7,7,9,7,7,9};
    int k = 7;
    int resu = s1.maxScore(cardPoints, k);
    cout << "resu = " << resu << endl;
    return 0;
}