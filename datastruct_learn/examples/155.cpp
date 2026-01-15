#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class MinStack {
public:
    MinStack() {
  
    }
    
    void push(int val) {
        data_Stack.push(val);
        minHeap.push(val);
    }
    
    void pop() {
        int delete_val = data_Stack.top();
        data_Stack.pop();
        vector<int>front_vec;
        while(minHeap.top() != delete_val ){
            front_vec.push_back(minHeap.top());
            minHeap.pop();
        }
        minHeap.pop();
        for(int i = 0; i< front_vec.size(); i++){
            minHeap.push(front_vec[i]);
        }

    }
    
    int top() {
        return data_Stack.top();
    }
    
    int getMin() {
        return minHeap.top();
    }
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    stack<int>data_Stack;
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

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp