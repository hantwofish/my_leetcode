### 第五章:堆与优先队列

```c++
priority_queue<int,vector<int>,greater<int>>myQueue; // 小堆
priority_queue<int,vector<int>,less<int>>myQueue; // 大堆(堆顶元素为最大值)
priority_queue<int>myQueue; // 大堆
```

priority_queue<Type, Container, Functional>> xxx;
（Type为数据类型， Container为保存数据的容器，Functional为元素比较方式。）

```c++
class node{
public:
    int m_x;
    int m_y;

};
struct cmp{
    bool operator()(const node&n1, const node &n2)
    {
        return n1.m_x > n2.m_x;
    }
};
priority_queue<node,vector<node>,cmp>my_Queue;

```