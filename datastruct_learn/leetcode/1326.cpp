#include"../STLCOMMON.h"
#include"../COMMONALO.h"
using namespace std;


typedef enum{
    IVAILD = -1,
    NOT_CHOOSE = 0,
    CHOOSED = 1
};


class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        N = n + 1;
        status.resize(N, IVAILD);
        nodeFlag.resize(N, false);
        int tiems = 0;
        for(int i = 0; i <= n; i++){
            if(nodeFlag[i]) continue;
            int switch_Inde = getSwitchIndex(i, ranges);
            cout << "i= " << i <<  " switch " << switch_Inde << endl;
            if(switch_Inde == -1){
                return -1;
            }
            tiems++;
            update(switch_Inde, ranges);
        }
        return tiems;
    }
    int getSwitchIndex(int cur, vector<int>& ranges)
    {
        // 寻找覆盖 cur 的最大的，
        int re_cur = -1;
        int right_boundl = -1;;
        for(int i = 0; i < N; i++){
            if(ranges[i] == 0) continue;
            if(status[i] == CHOOSED) continue;
            if(i - ranges[i] <= cur && i + ranges[i] > right_boundl ){
                re_cur = i;
                right_boundl = i + ranges[i];
            }
        }
        return re_cur;
    }
    void update(int cur, vector<int>& ranges)
    {
        status[cur] = CHOOSED;
        for(int i = (cur-ranges[cur]); i <= (cur+ranges[cur]); i++){
            if(i< 0 || i >= N) continue;
            nodeFlag[i] = true;
        }
    }
public: 
    vector<int>status;
    vector<bool>nodeFlag;
    int N = 0;
};
 

int main()
{
    int n = 3;
    // vector<int> ranges = {3,4,1,1,0,0};
    vector<int> ranges = {0,0,0};
    Solution s1;
    s1.minTaps(n, ranges);
    cout << "hell22o" << endl;
    return 0;
}