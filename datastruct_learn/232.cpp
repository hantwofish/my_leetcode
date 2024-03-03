#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
/*
1. 对于元素 b 来说，b 入队列。 b 要后删除，则b 需要在栈的底部
2. 将 main_stack 中元素出栈 压入 help_stack. 
3. 将 b main_stack 、则 b 正好在 main_stack 的底部
4. 将  help_stack 中元素出栈压入 main_stack

*/

class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        while(!main_stack.empty()){
            int top_val = main_stack.top();
            help_stack.push(top_val);
            main_stack.pop();
        }
        main_stack.push(x);


        while(!help_stack.empty()){
            int top_val = help_stack.top();
            main_stack.push(top_val);
            help_stack.pop();
        }
    }
    
    int pop() {
        int top_val = main_stack.top();
        main_stack.pop();
        return top_val;
    }
    
    int peek() {
        return  main_stack.top();
    }
    
    bool empty() {
        return  (main_stack.size() == 0);
    }
private:
    stack<int>main_stack;
    stack<int>help_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}