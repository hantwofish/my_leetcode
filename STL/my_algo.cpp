#include"../STLCOMMON.h"

using namespace std;
#define N 10

vector<int> g_myVec;

bool cmp(int x,int y)
{    
    return x > y; // greater<int>()
}

void test()
{
    auto it = g_myVec.begin();
    for(int i = 0;i < N; i++){
        g_myVec.push_back(rand()%10);
    }
    MyPrintOne(g_myVec);
    sort(g_myVec.begin(),g_myVec.end());
    MyPrintOne(g_myVec);
    sort(g_myVec.begin(),g_myVec.end(),cmp);
    MyPrintOne(g_myVec);

}

int main()
{
    test();
    return 0;
    
}