#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

class Solution{
public:
    void toposort(vector<vector<int>>figure, int nodeNum)
    {
        indig.resize(nodeNum, 0);
        for(int i =0; i< figure.size(); i++){
            int start_node = figure[i][0];
            int end_node = figure[i][1];
            indig[end_node]++;
        }
        for(int i= 0; i< nodeNum; i++){
            if(indig[i] == 0){
                stk.push(i);
            }
        }
        while(!stk.empty()){
            int topval = stk.top();
            cout << "topval= " << topval << endl;
            topoArry.push_back(topval);
            stk.pop();
            // 相应连接点入度减
            for(int i= 0; i< figure.size(); i++){
                if(figure[i][0] == topval ){
                    indig[figure[i][1]]--;
                    if(indig[figure[i][1]] == 0){
                        stk.push(figure[i][1]);
                    }
                }
            }
        }


    }
private:
    vector<int> indig;
    stack<int>stk;
    vector<int>topoArry;
};

int main()
{
        int N = 5;
    vector<vector<int>>nums ={
        {0,1,1},
        {0,2,1},
        {0,3,3},
        {0,4,6},
        {1,3,1},
        {2,3,7},
        {3,4,1}

    };
    Solution s1;
    s1.toposort(nums, N);
    cout<< "hello" << endl;
    return 0;
}