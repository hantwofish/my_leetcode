#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class PointCmp{
public:
    bool  operator()(const pair<int,int> &A, const pair<int,int> &B) const // const 不可少, 对于Pair需要将多种情况都讨论
    {
        if(A.first < B.first){
            return true;
        }else if(A.first == B.first) {
            return A.second < B.second;
        }
        
        return  false;
    }
};

class CountIntervals {
public:
    CountIntervals() {

    }
    
    void add(int left, int right) 
    {
        pair<int,int>temp = make_pair(left, right);
        auto it = mySet.begin();
        while(it!= mySet.end()){
            if(it->first > temp.first) break;
            
            
            it++;
        }


    }
    
    int count() {

    }

public:
    set<pair<int,int>,PointCmp>mySet;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}