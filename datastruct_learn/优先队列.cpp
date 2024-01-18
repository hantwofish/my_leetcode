#include"../STLCOMMON.h"

using namespace std;

typedef  struct{
    int x;
    int y;
}node;

struct rule{ // 按照结构体中 y 从大到小  (为ture 的时候进行交换)
    bool operator()(node a, node b){
        return a.y < b.y; 
    }

};

void test()
{
    int n =4;
    priority_queue<node, vector<node>, rule> a;
    for(int i =0 ; i< n; i++){
        node q;
        q.x = rand()% 30;
        q.y = rand()% 50;
        a.push(q);
    }
    cout << "print..." << endl;
    while(!a.empty()){
        cout << a.top().x << " " << a.top().y << endl;
        a.pop();
    }
}


int main()
{
    // priority_queue<int,vector<int>,less<int>> que; // 大顶堆
    // priority_queue<int,vector<int>,greater<int>> que; // 小顶堆
    priority_queue<int> que; // 默认大顶堆
    que.push(1);
    que.push(0);
    que.push(2);
    cout << que.top() << endl;
    que.pop();
    cout << que.top() << endl;


    cout << "hello word" << endl;
    test();
    return 0;

}