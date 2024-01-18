#include"../STLCOMMON.h"

using  namespace std;

class Solution{
public:
    int CalSwitchOnTime(vector<vector<int>>& inputD)
    {

        switchAndTime.resize(4, vector<int>(50,0));
        MyPrintTwo(switchAndTime);
        switchOpenTime.resize(4,0);
        const int endTime = inputD[inputD.size()-1][0];
        cout << "endTime= " << endTime << endl;


        int index = 0;
        for(int time = 0; time <= endTime; time++){
            cout << "tiem= " << time << endl;
            ChageAllSwitchgStatus(time);
            if( time == inputD[index][0]){
                cout << "inputD time= " << inputD[index][0] << endl;
                // 更新开关状态
                int switChNum = inputD[index][1];
                if(  time == 0){
                    switchAndTime[switChNum][time] = 1;
                    switchOpenTime[switChNum] = time;
                    continue;
                }

                StatusF(switchAndTime[switChNum][time]);
                if(switchAndTime[switChNum][time] == 1){
                    switchOpenTime[switChNum] = time;
                }
                index++;
            }
        }
        MyPrintTwo(switchAndTime);

        return 0;

    }
    void ChageAllSwitchgStatus(int curTime)
    {
        if(curTime == 0){
            return;
        }
        cout << "ChageAllSwitchgStatus curTime = " << curTime << endl;
        for(int i = 1; i<= 3; i++){
            cout << "ChageAllSwitchgStatus i= " << i << "  switchOpenTime[i]= " << switchOpenTime[i] << endl;
            if(curTime - switchOpenTime[i] >= limitTime){
                
                if( switchAndTime[i][curTime - 1] == 1){
                    switchAndTime[i][curTime] = 0;
                }
                cout << "ChageAllSwitchgStatus if   switchOpenTime = " << switchOpenTime[i] << endl;
            }else{
                cout << "else" << endl;
                switchAndTime[i][curTime] = switchAndTime[i][curTime - 1];
                cout << "ChageAllSwitchgStatus  else   switchOpenTime = " << switchOpenTime[i]  << endl;
            }
        }
        cout << "ChageAllSwitchgStatus end curTime = " << curTime << endl;

    }

    void StatusF(int &nums)
    {
        if(nums == 0){
            nums = 1;
        }else{
            nums == 0;
        }
    }


public:
    vector<vector<int>> switchAndTime;
    vector<int> switchOpenTime;  // 记录各个开关上次开启的时间

    int limitTime = 4;


};


int main()
{

    vector<vector<int>> inputDa ={
        {1,2},{2,3},{6,3},{10,1}
    };
    MyPrintTwo(inputDa);
    Solution s1;
    s1.CalSwitchOnTime(inputDa);

    cout << "---end---" << endl;
    return 0;
}