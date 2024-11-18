#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>

#define TIMEINTERVAL 5

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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        N = n;
        UnionFind u1(n);
        figure.resize(n, vector<int>(n, 0));
        for(int i = 0; i < edges.size(); i++){
            
                
            int x = edges[i][0];
            int y = edges[i][1];
            figure[x][y] = 1;
            figure[y][x] = 1;

            u1.unionNode(x, y);      
        }
        // for(int i = 0; i < edges.size(); i++){

        //     int x = edges[i][0];
        //     int y = edges[i][1];

        //     mp[u1.find_fa(x)].insert(x);
        //     mp[u1.find_fa(y)].insert(y);
        //     cout << " " << x << " " <<y << " { "<< u1.find_fa(x) << ", " << u1.find_fa(y) <<  " }" << endl;
        // }

        for(int i = 0; i< n; i++){
            // u1.unionNode(i, i);  
            mp[u1.find_fa(i)].insert(i);
            cout << " i= " << i << " { " << u1.find_fa(i) <<  " }" << endl;
        }


        int resu  = 0;
        auto it = mp.begin();
        while(it != mp.end()){
            vector<int>temp(it->second.begin(), it->second.end()); 
            if(isVaild(temp)){
                resu++;
            }
            it++;   
        }
        cout << "resu = " << resu << endl;
        return resu;
    }
    bool isVaild(vector<int>&vec)
    {
        MyPrintOne(vec);
        for(int i = 0; i< vec.size(); i++){
            for(int j = 0; j < vec.size(); j++){
                if(vec[i] == vec[j]) continue;
                if(figure[vec[i]][vec[j]] == 0) return false;
            }
        }
        return true;

    }
public:
    int N;
    unordered_map<int, set<int>>mp;
    vector<vector<int>>figure;
};

int mainFunc()
{
    Solution s1;
    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4},{3,5}};
    //   vector<vector<int>> edges =    {{0,1},{0,2},{1,2},{3,4}};
    s1.countCompleteComponents(n, edges);

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