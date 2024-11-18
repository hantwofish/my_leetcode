#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        
        myPriQ.push(t);
        
        int limitVal = t - N;
        
        while(!myPriQ.empty() &&  myPriQ.top() < limitVal){
            cout << myPriQ.top() << " " << limitVal << endl;
            myPriQ.pop();
        }

        return myPriQ.size();
    }
private:
    map<int,int>myMap;
    int N = 3000;
    priority_queue<int,vector<int>, greater<int>>myPriQ;
    
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