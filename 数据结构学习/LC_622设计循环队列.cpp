#include"../STLCOMMON.h"
using namespace std;
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        N = k;
        vecque.resize(N,0);
    }
    
    bool enQueue(int value) {
        if(isFull()){
            cout << "enQueue false" << " value= " << value << endl;
            return false;
        }
        vecque[endIndex] = value;
        endIndex++;
        cout << "enQueue true" << " value= " << value << "frontIndex= " << frontIndex << " endIndex= " << endIndex << endl;
        return true;

    }
    
    bool deQueue() {
        if(isEmpty()){
            cout << "deQueue false" << endl;
            return false;
        }

        frontIndex ++;
        cout << "deQueue true" <<   " frontIndex= " << frontIndex << " endIndex= " << endIndex <<   endl;
        return true;
        
        
    }
    
    int Front() {
        int temp = vecque[frontIndex];
        cout << "Front " <<temp << endl;
        return temp;
    }
    
    int Rear() {
        int index = 0;
        if(endIndex == 0){
            index = N-1;
        }
        
        int temp = vecque[index];
        cout << "Rear= "<< temp << endl;
        return temp ;

    }
    
    bool isEmpty() {
        if(QueSize() == 0){
            cout << "isEmpty true" << endl;
            return true;
        }else{
            cout << "isEmpty false" << endl;
            return false;
        }
    }
    
    bool isFull() {
        if(QueSize() == N){
            cout << "isFull true" << endl;
            return true;
        }else{
            cout << "isFull false" << endl;
            return false;
        }

    }
    int QueSize()
    {
        if(endIndex >= frontIndex){
            return endIndex - frontIndex;
        }else{
            return endIndex + N - frontIndex;
        }

    }

private:
    vector<int>vecque;
    int N;
    int frontIndex = 0;
    int endIndex = 0;// 填充的后一个
    // int queSize =0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

class MyCircularQueue2 {
public:
    MyCircularQueue2(int k) {
        N =k;

    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        que.push(value);
        return true;

    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        que.pop();
        return true;

    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return que.front();

    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return que.back();
    }
    
    bool isEmpty() {
        if(que.size()==0){
            return true;
        }
        return false;

    }
    
    bool isFull() {
        if(que.size()==N){
            return true;
        }
        return false;

    }
public:
    int N;
    queue<int> que;
};

int main()
{
    int k = 3;
    MyCircularQueue* circularQueue = new MyCircularQueue(k);
    circularQueue->enQueue(1); // 返回 true
    circularQueue->enQueue(2); // 返回 true
    circularQueue->enQueue(3); // 返回 true
    // cout << "xxxx QueSize= " << circularQueue->QueSize() << endl; 
    circularQueue->enQueue(4); // 返回 false，队列已满
    circularQueue->Rear(); // 返回 3
    circularQueue->isFull(); // 返回 true
    circularQueue->deQueue(); // 返回 true
    circularQueue->enQueue(4); // 返回 true
    circularQueue->Rear(); // 返回 4



    return 0;
}