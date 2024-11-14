#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int times = 0;
        int max_postion = startFuel;
        int cur_fuel = startFuel;
        isVisited.resize(stations.size(), 0);
        while(max_postion < target){
            // 1. 将所有距离之间的加油站的值都放到优先队列中
            for(int i =0; i< stations.size(); i++){
                if(isVisited[i]) continue;
                if(stations[i][0] <= max_postion){
                    que.push(stations[i][1]);
                    isVisited[i] = true;
                }
            }
            // 2. 
            if(max_postion >= target){
                return times;
            }else{
                if(que.empty()) return -1;
                max_postion += que.top();
                times++;
                que.pop();
            }
        }

        return times;
    }
private:
    priority_queue<int>que;
    vector<int>isVisited;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}