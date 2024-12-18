#include"../STLCOMMON.h"

using namespace std;

bool CMP(int& a, int& b)
{
    return a > b;
}
class Vec{
public:
    void init()
    {
        vec.push_back(-1);
        vec.push_back(2);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        MyPrintOne(vec);
        sort(vec.begin(),vec.end());
        MyPrintOne(vec);
        sort(vec.begin(),vec.end(),CMP);
        MyPrintOne(vec);


    }


public:
    vector<int>vec;
};

reverse(myVec.begin(),myVec.end()); 翻转

int main()
{
    Vec v1;
    v1.init();
    return 0;
    
}