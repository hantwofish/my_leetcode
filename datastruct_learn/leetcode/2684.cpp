#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
// DFS 超时
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        resu = 0;
        for(int i= 0; i < N; i++){
            nums.clear();
            // nums.push_back(grid[i][0]);
            cout << "main push " << grid[i][0] << endl;
            Dfs(grid, i, 0, i, 0);
        }
        if(resu <= 1) return  0;

        cout << "resu= " << resu << endl;
        return resu - 1; 
    }
    void Dfs(vector<vector<int>>& grid, int start_i, int start_j, int cur_i, int cur_j)
    {
 
        if(cur_i>= N || cur_i < 0|| cur_j >= M || cur_j < 0){
            // MyPrintOne(nums);
            resu = max(resu, (int)nums.size());
            return;
        }
        if(nums.empty() ) {
            nums.push_back(grid[cur_i][cur_j]);
        }else{
            if(grid[cur_i][cur_j] > nums[nums.size()-1]){
                nums.push_back(grid[cur_i][cur_j]);
                resu = max(resu, (int)nums.size());
            }else{
                return;
            }
               
        
        }


        
        // if(grid[cur_i][cur_j] < nums[nums.size()-1]) return;


        // if(cur_i -1 > 0 && cur_i -1 < N && cur_j + 1 < M && grid[cur_i -1][cur_j + 1] > grid[cur_i][cur_j ]){
            Dfs(grid, start_i, start_j, cur_i -1, cur_j + 1);
        // }
        // if(cur_i  < N && cur_j + 1 < M && grid[cur_i ][cur_j + 1] > grid[cur_i ][cur_j ]){
            Dfs(grid, start_i, start_j, cur_i , cur_j + 1);
        // }      

        // if(cur_i + 1 < N && cur_j + 1 < M && grid[cur_i + 1][cur_j + 1] > grid[cur_i ][cur_j]){
            Dfs(grid, start_i, start_j, cur_i + 1, cur_j + 1);
        // }
        if(nums.size() >= 1){
            nums.pop_back();
        }
       
    }
private:
    vector<int>nums;
    int N ,M;
    int resu;
    // int starti, startj;
    vector<int>startj;
};

int main()
{
    Solution s1;
    // vector<vector<int>> grid = {{2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15}};
    vector<vector<int>> grid ={{3,2,4},{2,1,9},{1,1,7}};
    // vector<vector<int>> grid = {{187,167,209,251,152,236,263,128,135},
    //                             {267,249,251,285,73,204,70,207,74},
    //                             {189,159,235,66,84,89,153,111,189},
    //                             {120,81,210,7,2,231,92,128,218},
    //                             {193,131,244,293,284,175,226,205,245}};
    s1.maxMoves(grid);
    
    

    cout << "hell22o" << endl;
    return 0;
}