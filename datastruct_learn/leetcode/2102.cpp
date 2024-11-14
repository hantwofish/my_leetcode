#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class PointCmp{
public:
    bool  operator()(const pair<string,int> &A, const pair<string,int> &B) const // const 不可少, 对于Pair需要将多种情况都讨论
    {
        if(A.second > B.second){
            return true;
        }else if(A.second == B.second) {
            return A.first < B.first;
        }
        
        return  false;
    }
};
class SORTracker {
public:
    SORTracker() {

    }
    
    void add(string name, int score) {
        mySet.insert({name,score});
    }
    
    string get() {
        auto it = mySet.begin();
        int tempTimes = times;
        while(tempTimes > 1){
            it++;
            tempTimes--; 
        }
        string resu = it->first;
        times++;
        return resu;
    }
private:
    set<pair<string,int>,PointCmp>mySet;
    int times = 1;
};
 

int main()
{
    long long num = 0;
    long long minNum =  -1 * ( (long long)1 << 32);
    long long maxNum = (long long)1 << 32;
    cout << minNum << endl;
    cout << maxNum << endl;
    
    cout << "hell22o" << endl;
    return 0;
}