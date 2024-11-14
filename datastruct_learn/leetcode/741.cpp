#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>

#define TIMEINTERVAL 20

using namespace std;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    // std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << endl;
    cout << "[error] timer " <<  seconds << " is over exit " << endl;
    exit(1);
}



class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        N = grid.size();
        M= grid[0].size();
        findPath(grid, 0,0);
        for(int i= 0; i< allPatch.size(); i++){
            for(int j = 0; j < allPatch[i].size(); j++){
                printf("{%d, %d} ", allPatch[i][j].first, allPatch[i][j].second);
            }
            printf("\n");
        }

        onePatch.clear();
        findPathUp(grid, N-1,M-1);
        for(int i= 0; i< allPatchUp.size(); i++){
            for(int j = 0; j < allPatchUp[i].size(); j++){
                printf("{%d, %d} ", allPatchUp[i][j].first, allPatchUp[i][j].second);
            }
            printf("\n");
        }

        
        return getNUm(grid);
    }

    int getNUm(vector<vector<int>>& grid)
    {
        int resuOut = 0;
        for(int i = 0; i< allPatch.size(); i++){
            for(int j = 0; j< allPatchUp.size(); j++){
                vector<pair<int,int>>leftVec = allPatch[i];
                vector<pair<int,int>>rightVec = allPatchUp[j];
                set<pair<int,int>>SetVec ;
                for(int i = 0; i< leftVec.size(); i++){
                    SetVec.insert(leftVec[i]);
                }                
                for(int i = 0; i< rightVec.size(); i++){
                    SetVec.insert(rightVec[i]);
                }
                int resu = 0;
                auto it = SetVec.begin();
                while(it != SetVec.end()){
                    resu +=  grid[it->first][it->second];
                    it++;
                }
                resuOut = max(resuOut,resu );
                cout << "resu=  " << resu << endl;

            }
        }
        cout << "resuOut= " << resuOut << endl;
        return resuOut;
    }
    // 找到 从左上角到右下角的所有路径
    void findPath(vector<vector<int>>& grid, int cur_i, int cur_j)
    {
        if(cur_i >=  grid.size() || cur_j >= grid[0].size()){   
            return;
        }
        if( cur_i == grid.size() -1 &&  cur_j >= grid[0].size()- 1){
            
            onePatch.push_back({cur_i,cur_j});
            allPatch.push_back(onePatch);
            onePatch.pop_back();
            return;
        }

        if(grid[cur_i][cur_j] ==  -1){
            return;
        }
        onePatch.push_back({cur_i,cur_j});
        // cout << "push " << " {"<< cur_i << " , " << cur_j << "}" << endl;
        for(int i =0; i < dir.size(); i++){
            pair<int,int>nexNode = make_pair(cur_i+dir[i][0], cur_j + dir[i][1]);
            findPath(grid,nexNode.first, nexNode.second );
        }
        onePatch.pop_back();

    }
    void findPathUp(vector<vector<int>>& grid, int cur_i, int cur_j)
    {
        if(cur_i <  0 || cur_j < 0){   
            return;
        }
        if(grid[cur_i][cur_j] ==  -1){
            return;
        }
        if( cur_i == 0 &&  cur_j == 0){
            
            onePatch.push_back({cur_i,cur_j});
            allPatchUp.push_back(onePatch);
            onePatch.pop_back();
            return;
        }


        onePatch.push_back({cur_i,cur_j});
        // cout << "push " << " {"<< cur_i << " , " << cur_j << "}" << endl;
        for(int i =0; i < dirUp.size(); i++){
            pair<int,int>nexNode = make_pair(cur_i+dirUp[i][0], cur_j + dirUp[i][1]);
            findPathUp(grid,nexNode.first, nexNode.second );
        }
        onePatch.pop_back();

    }
private: 

private:    
    vector<pair<int,int>>onePatch;
    vector<vector<pair<int,int>>>allPatch;
    vector<vector<pair<int,int>>>allPatchUp;
    vector<vector<int>>dir = {{0,1},{1,0}};
    vector<vector<int>>dirUp = {{0,-1},{-1,0}};
    int N = 0;
    int M = 0;
};

int mainFunc()
{
    Solution s1;
    vector<vector<int>> grid = {{0,1,-1},{1,0,-1},{1,1,1}};
    // vector<vector<int>> grid = {{1,1,-1},{1,1,-1},{1,1,-1}};
    s1.cherryPickup(grid);
    return 0;
}

int main()
{
    std::cout << "[info] Starting timer for " << TIMEINTERVAL << " seconds" << std::endl << std::endl;
    std::thread timer_thread(timer_function, TIMEINTERVAL); // 设置计时器延时 TIMEINTERVAL 秒

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    timer_thread.join(); // 等待计时器线程完成
    std::cout << "[info] Timer thread finished" << std::endl;
    return 0;
}