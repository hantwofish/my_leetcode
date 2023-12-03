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
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
         N  = mat.size();
         M = mat[0].size();
        vector<vector<bool>> isVisted(N, vector<bool>(M,false));
        rowarry.resize(N,0);
        colarry.resize(M,0);
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                pair<int, int>tempPair = make_pair(i, j);
                mymap.insert({mat[i][j], tempPair});
            }
        }
        for(int i= 0; i < arr.size(); i++){
            int val = arr[i];
            pair<int,int>valindex = mymap[val];
            int rowindex = valindex.first;
            int colindex = valindex.second;

            isVisted[rowindex][colindex] = true;
            rowarry[rowindex]++;
            colarry[colindex]++;
            
            if((rowarry[rowindex] == M) || (colarry[colindex] == N)){
                return i;
            }
        }

        return 0;
        
    }
    bool isRow(int i, int j, vector<vector<bool>>&isVisted)
    {
        for(int k = 0; k < M; k++){
            if(isVisted[i][k] == false){
                return false;
            }
        }
        return true;
    }
    bool isCol(int i, int j, vector<vector<bool>>&isVisted)
    {
        for(int k = 0; k < N; k++){
            if(isVisted[k][j] == false){
                return false;
            }
        }
        return true;
    }
public:
    unordered_map<int,pair<int,int>>mymap;
    int N;
    int M;
    vector<int>rowarry; // 记录每一行被涂色的个数
    vector<int>colarry;
};

int main()
{
    Solution s1;
    

    cout << "hello" << endl;
    return 0;
}