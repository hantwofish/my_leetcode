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
    void gameOfLife(vector<vector<int>>& board) {
        oldbBoard = board;
        int row = board.size();
        int col = board[0].size();
        N = row;
        M = col;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col ;j++){
                // neigh live
                int neigh_live = 0;
                int neigh_die = 0;
                getneighstatus(neigh_live,neigh_die, i, j);
                board[i][j] = startschage(board[i][j], neigh_live, neigh_die);
                cout << "i= " << i << " j= " << j << " live= " << neigh_live << " die= " << neigh_die <<  " status= " << board[i][j] << endl;
            }
        }
    }
    void getneighstatus(int &neigh_live, int &neigh_die, int i, int j)
    {
        int row1 = i -1;
        row1 = row1 < 0 ? 0 : row1;
        int row2 = i+ 1;
        row2 = (row2 >= N) ? (N-1) : row2;
        int col1 = j -1;
        col1 = (col1 < 0) ? 0 : col1;
        int col2 = j+ 1;
        col2 = (col2 >= M) ? (M-1) : col2;
        neigh_die = neigh_live = 0;
        for(int i_1 = row1; i_1<= row2; i_1++){
            for(int j_1 = col1; j_1 <= col2; j_1++){
                if(i_1 == i && j_1 == j){
                    continue;
                }
                if(oldbBoard[i_1][j_1] == 0){
                    neigh_die++;
                }else{
                    neigh_live++;
                }
                
            }
        }
    }
    int startschage(int status, int live_num, int die_num)
    {
        if(status == 1){
            if(live_num < 2) {
                return 0;
            }else if(live_num == 2 || live_num == 3){
                return 1;
            }else if(live_num > 3){
                return 0;
            }

        }else{
            if(live_num == 3){
                return 1;
            }
        }
        return 0;
    }

public:
    vector<vector<int>> oldbBoard;
    int N = 0;
    int M = 0;
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    

    cout << "hello" << endl;
    return 0;
}