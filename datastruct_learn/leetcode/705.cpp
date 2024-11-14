#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;



class MyHashSet {
public:
    MyHashSet() {
        nums.resize(1e6 +1, 0);
    }
    
    void add(int key) {
        nums[key] = 1;
    }
    
    void remove(int key) {
        nums[key] = 0;
    }
    
    bool contains(int key) {
        return nums[key] > 0;
    }
private:
    vector<int>nums;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int mainFunc()
{
    Solution s1;

    return 0;
}

int main()
{

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}