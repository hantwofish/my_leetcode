#include"../STLCOMMON.h"

using namespace std;





int main()
{
    int N = 0;
    vector<int>data;
    while(cin>> N){
        if(N == 0){
            break;
        }
        data.clear();
        for(int i =0; i < N; i++){
            int temp;
            cin >> temp;
            data.push_back(temp);
        }
        MyPrintOne(data);

    }
    return 0;
}