#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        N = nextVisit.size();
        // visited.resize(N, 0);
        int curNode = 0;
        int dayTimes = 0;
        cout << "N= " << N << endl;


        while(1){
            
            // visited[curNode] = true;
            NodeVisited.insert(curNode);
            visitedTimes[curNode]++;
            // cout << "dayTimes= "<< dayTimes <<  " curnode= " << curNode  << " times= " << visitedTimes[curNode] <<  endl;
            
            
            cout << "vise size= " << NodeVisited.size() << endl;
            if(isAllVisited() ){
                break;
            }

            int nextNode = 0;
            int times = visitedTimes[curNode];
            int index = 0;
            if(times % 2 == 1){
                index = curNode;
                nextNode = nextVisit[index];
            }else{
                index = (curNode + 1) % N; 
                nextNode = index;     
            }
            // cout << " idnex= " << index  << " nexNode= " << nextNode << endl;
            
            curNode = nextNode;
            dayTimes++;
            while(day_times > MOD){
                day_times -= MOD;
            }


        }
        return dayTimes;
    }
    bool isAllVisited()
    {
        // for(int i = 0; i< visited.size(); i++){
        //     if(visited[i] == 0){
        //         return false;
        //     }
        // }
        // return true;
        if(NodeVisited.size() == N){
            // MyPrintOne(NodeVisited);
            return true;
        }
        return false;
    }
private:
    int day_times = 0;
    int N ;
    // vector<int>visited;
    unordered_map<int, int>visitedTimes;
    int MOD = 1e9+7;
    set<int>NodeVisited;
};

int main()
{
    Solution s1;
    vector<int> nextVisit = {0,1,2,0};
    int resu = s1.firstDayBeenInAllRooms(nextVisit);
    cout << "main resu= " << resu << endl;
    

    cout << "hell22o" << endl;
    return 0;
}