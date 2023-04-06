#include"../../STLCOMMON.h"
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

bool CMp(vector<int>&A, vector<int>&B)
{
    if( A[0] < B[0]){
        return true;
    }
    return A[2] < B[2];
}


class Solution{
public:
    vector<int> CalNeedNum(vector<vector<int>> &inputData)
    {
        inputData.insert(inputData.begin(), {0,0});
        for(int i = 0; i < inputData.size(); i++){
            inputData[i].push_back(i);
        }
        MyPrintTwo(inputData);




        sort(inputData.begin(), inputData.end(), CMp);
        MyPrintTwo(inputData);

        int N  =inputData.size();
        isUsed.resize(N , 0);
        resu.resize(N,0);
        isComplete.resize(N,0);
        int endTime = 0;
        int startTime = INT32_MAX;
        for(int i = 1; i< N; i++){
            startTime = min(startTime, inputData[i][0]);
            endTime = max(endTime, inputData[i][1]);
        }


        // cout << "startTime= " << startTime << " endTime= " << endTime << " N= " << N << endl;

        int index = 1;
        for(int curTiem = startTime; curTiem <= endTime; curTiem++){
            // cout << " curTiem=  " << curTiem  << endl;
            // 遍历，释放机器
            for(int i = 1; i < N; i++){
                if(isComplete[i]){
                    continue;
                }
                if(inputData[i][1] < curTiem){
                    isUsed[i]  = false;
                    isComplete[i] = true;
                }
                // cout <<" for i = " << i << endl;
                
            }
            // MyPrintOne(isUsed);

            // cout << "index= " << index << endl;
            while(index < N && curTiem == inputData[index][0] ){
                // cout << "index= " << index << endl;
                int machinNum = FindVaildIndex();
                // cout << "machinNum= " << machinNum << endl;
                resu[inputData[index][2]] = machinNum;
                isUsed[machinNum] = true;
                index++;
            }
            // cout << "--- " << endl;
            // MyPrintOne(isUsed);
        }
        // cout << " for end " << endl;

        // MyPrintOne(resu);

        return resu;
    }
    int FindVaildIndex()
    {
        for(int i = 1; i < isUsed.size(); i++){
            if( isUsed[i] == false){
                return i;
            }
        }
        return 0;
    }

public:
    vector<bool> isUsed;
    vector<int> resu;
    vector<bool> isComplete;
};



void GetInputData(vector<vector<int>> &inputDta , int &N)
{
    cin >> N  ;
    inputDta.clear();
    inputDta.resize(N, vector<int>(2,0));
    for(int i = 0; i< N; i++){
        for(int j = 0 ; j < 2; j++){
            int a = 0;
            cin >> a;
            inputDta[i][j] = a;
        }
    }

}


int main()
{

    
    vector<vector<int>> inputDta = {
        {1, 4},
        {2, 6},
        {1, 5},
        {5, 7},
        {5, 9},
        {3, 4},
        {1, 3},
        {5, 8},
        {4, 5},
        {3, 8}
    };
    int N = inputDta.size();
    // MyPrintTwo(inputDta);


    // GetInputData(inputDta , N);

    Solution s1;
    vector<int>resu = s1.CalNeedNum(inputDta);
    // MyPrintOne(resu);
    set<int>st;
    for(int  i =1; i< resu.size();i++){
        st.insert(resu[i]);
    }
    cout<< st.size() << endl;;
    for(int i =1; i < resu.size()-1; i++){
        cout << resu[i] << endl;
    }
    cout << resu[resu.size()-1];


    return 0;
}