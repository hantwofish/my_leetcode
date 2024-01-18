
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

bool CMp(vector<float>&A, vector<float>&B)
{
    return A[A.size()-1] < B[B.size()-1];
}

int CalNeedNum(vector<vector<int>> inputData, int r)
{
    vector<vector<float>> nums;
    for(int i = 0; i < inputData.size(); i++){
        int x =  inputData[i][0];
        int y =  inputData[i][1];
        if( y > r || y < -r){
            return -1;
        }

        float diff = sqrt(r*r - y*y);
        nums.push_back({x-diff,  x+diff});
        // cout << "i=  " << i << " " << x- diff << " " << x+ diff << endl;
    }
    sort(nums.begin(), nums.end(), CMp);
    // MyPrintTwo(nums);

    float posLoaction = nums[0][1];
    int resu = 1;
    for(int i = 0; i< nums.size(); i++){
        if(nums[i][0] <= posLoaction){
            continue;
        }
       
        posLoaction = nums[i][1];
        resu++;
        
    }

    return resu;

}

void GetInputData(vector<vector<int>> &inputDta , int &N, int &r)
{
    cin >> N >> r;
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
    // float r = 2;
    // float x = 2;
    // float y  =1;
    // float diff = sqrt(r*r - y *y);


    // cout << "diff= " << diff << endl;
    // // 只保留两位小数
    // diff = diff * 100 / 100.0;
    // cout << "diff= " << diff << endl;
    
    vector<vector<int>> inputDta = {
        {1,2},{-3,1},{2,1}
    };
    int N = inputDta.size();
    int r =2;

    GetInputData(inputDta , N,  r);
    int resu = CalNeedNum(inputDta, r);
    // cout << "resu = " << resu << endl;
    cout << resu << endl;

    return 0;
}