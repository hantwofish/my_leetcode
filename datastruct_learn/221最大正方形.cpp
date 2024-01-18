#include"../STLCOMMON.h"
#include"../COMMONALO.h"
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
    int maximalSquare(vector<vector<char>>& matrix) {
        int N =matrix.size();
        int M = matrix[0].size();
        int resu = 0;
        for(int i = 0; i< N; i++){
            for(int j = 0; j< M; j++){
                if(matrix[i][j] == '0' ) continue;
                for(int width = 1; width <= min(N,M); width++){
                    if(i+ width -1 >= N || j +width -1 >= M) continue;
                    bool flag = isVaild(matrix, i, i+width-1, j, j+width-1 );
                    if(flag){
                        resu = max(resu, width*width);
                    }


                }
            }
        }
        return resu;

    }
    bool isVaild(vector<vector<char>>& matrix,int i_begin, int i_end, int j_begin, int j_end)
    {
        for(int i= i_begin; i<= i_end; i++){
            for(int j = j_begin; j <= j_end; j++){
                if(matrix[i][j] == '0'){
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    

    

    cout << "hell3322o" << endl;
    return 0;
}