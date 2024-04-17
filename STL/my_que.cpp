class MyCompareMAX{
public:
    bool operator()(pair<int , int>a , pair<int , int>b){
        return a.second < b.second;
    }
};
class MyCompareMIN{
public:
    bool operator()(pair<int , int>a , pair<int , int>b){
        return a.second > b.second;
    }
};

    priority_queue<pair<int,int>,vector<pair<int,int>>,MyCompareMAX>maxQue;// 大顶堆
    priority_queue<pair<int,int>,vector<pair<int,int>>,MyCompareMIN>minQue; // 小顶堆

    deque<int>ps; // 双端队列

int main()
{
    queue<pair<int,int>> qu;
    qu.push({1,2});
    cout << "que.size= " << qu.size() << endl;
    qu.pop();
    cout << "que.size= " << qu.size() << endl;

    maxQue.push({1,2});
    cout << "maxQue.size= " << maxQue.size() << endl;
    maxQue.pop();
    cout << "maxQue.size= " << maxQue.size() << endl;
    cout << "hell22o" << endl;
    return 0;
}