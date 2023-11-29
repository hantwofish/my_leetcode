#include"../STLCOMMON.h"
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


// 维持一个小顶堆，一个栈
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        mystk.push(val);
        myque.push(val);
        myset.insert(val);
    }
    
    void pop() {
        int val =mystk.top();
        mystk.pop();
        // if(val == myque.top()){
        //     myque.pop();
        // }
        // 找到要删除的元素，进行删除
        vector<int>resu;
        while(myque.top()!= val){
            int temp = myque.top();
            resu.push_back(temp);
            myque.pop();
        }
        myque.pop();
        for(int i = 0; i < resu.size(); i++){
            myque.push(resu[i]);
        }
        
       

    }
    
    int top() {
        return mystk.top();
    }
    
    int getMin() {
        return myque.top();
    }
public:
    stack<int> mystk;
    priority_queue<int, vector<int>, greater<int>>myque;
    multiset<int>myset;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */




int main()
{
    Solution s1;
    

    cout << "hello" << endl;
    return 0;
}