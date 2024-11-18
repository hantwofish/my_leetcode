#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "TREE.h"



#define TIMEINTERVAL 1

using namespace std;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    // std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << endl;
    cout << "[error] timer " <<  seconds << " is over exit " << endl;
    exit(1);
}



class Solution {
public:
    int maxDepth(Node* root) {
        int resu = 0;
        que.push(root);
        while(!que.empty()){
            resu++;
            int N = que.size();
            for(int i= 0; i < N;i++){
                Node * topVal = que.front();
                for(int j = 0; j < topVal->children.size();j++){
                    que.push((topVal->children)[j]);
                }
                que.pop();
            }

        }
        return resu;
    }
private:
    queue<Node*>que;
};

int mainFunc()
{
    Solution s1;

    return 0;
}

int main()
{
    std::cout << "[info] Starting timer for " << TIMEINTERVAL << " seconds" << std::endl << std::endl;
    std::thread timer_thread(timer_function, TIMEINTERVAL); // 设置计时器延时 TIMEINTERVAL 秒

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    timer_thread.join(); // 等待计时器线程完成
    std::cout << "[info] Timer thread finished" << std::endl;
    return 0;
}