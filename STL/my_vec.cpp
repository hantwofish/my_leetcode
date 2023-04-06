#include"../STLCOMMON.h"

using namespace std;
#define N 10

vector<int> g_myVec;

void test()
{
    auto it = g_myVec.begin();
    for(int i = 0;i < N; i++){
        g_myVec.push_back(i);
    }
    MyPrintOne(g_myVec);
    it = find(g_myVec.begin(),g_myVec.end(), 1);
    cout << "index= " << it - g_myVec.begin() << endl;
    

}

int main()
{
    test();
    return 0;
    
}