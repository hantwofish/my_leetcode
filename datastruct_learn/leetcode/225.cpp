#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

/*
1. 数据 a 先入 help_quue; // 对于栈是最先出队的，要保证数据 a 在队列头
2. 将 main_que 中数据依次出队，入队到 help_que;
3. 将help_que 赋值给mainque. // 此时数据a 在队头

*/

class MyStack {
public:
    MyStack() {
    }
    
    void push(int x) {
        help_que.push(x);
        while(!main_que.empty()){
            int top_val = main_que.front();
            help_que.push(top_val);
            main_que.pop();
        }
        main_que = help_que;

        while(!help_que.empty()){
            help_que.pop();
        }

    }
    
    int pop() {
        int top_val = main_que.front();
        main_que.pop();
        return top_val;
    }
    
    int top() {
        return main_que.front();
    }
    
    bool empty() {
        return (main_que.size() == 0);
    }

private:
    queue<int>main_que;
    queue<int>help_que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}