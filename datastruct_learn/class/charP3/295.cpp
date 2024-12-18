#include"../../STLCOMMON.h"
using namespace std;

// 超时
class MedianFinder {
public:
    MedianFinder() {
        myQueue.empty();
    }
    
    void addNum(int num) {
        myQueue.push(num);
    }
    
    double findMedian() 
    {
        priority_queue<int,vector<int>,greater<int>>myQueueTemp = myQueue;
        int mid1 =0;
        int mid2 = 0;
        double resu = 0;
        int N = myQueueTemp.size();
        if(N %2 == 0){
            // 出队 (n-2)/2
            myPop(myQueueTemp,(N-2)/2);
            mid1 = myQueueTemp.top();
            myPop(myQueueTemp, 1);
            mid2 = myQueueTemp.top();
            resu = (mid1 + mid2 )/ 2.0;

        }else{
            myPop(myQueueTemp, (N-1)/2);
            mid1 =  myQueueTemp.top();
            resu = mid1;
        }
        return resu;
    }
    void PrintQue()
    {
       
    }
    void myPop(priority_queue<int,vector<int>,greater<int>>&myQueueTemp,int n)
    {
        for(int i = 0; i< n ; i++){
            myQueueTemp.pop();
        }
    }
public:
    priority_queue<int,vector<int>,greater<int>>myQueue;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class node{
public:
    int m_x;
    int m_y;

};
bool Mycompare(node& n1, node &n2)
{
    return n1.m_x > n2.m_x;
}

struct cmp{
    bool operator()(const node&n1, const node &n2)
    {
        return n1.m_x > n2.m_x;
    }
};


int main()
{
    priority_queue<node,vector<node>,Mycompare>my_Queue;
    priority_queue<node,vector<node>,cmp>my_Queue;


    MedianFinder* obj = new MedianFinder();
    // vector<int>nums ={-1,-2,-3,-4,-5};
    vector<int>nums={1,2,3};
    for(int i =0; i< nums.size();i++){
        obj->addNum(nums[i]);
        cout << obj->findMedian() << endl;
    }

    double param_2 = obj->findMedian();
    cout << "resu = " << param_2 << endl;

}