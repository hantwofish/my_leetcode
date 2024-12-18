class MyCompareMAX{
public:
    bool operator()(pair<int , int>a , pair<int , int>b){
        return a.second < b.second;
    }
};
class MyCompareMIN{
public:
    bool operator()(pair<int , int>a , pair<int , int>b){
        return a.second > b.second; // 大于的时候进行交换
    }
};

// 按照 second 从小到大排序，second 相等的时候，优先 first 小的
// class MyCompareMIN{
// public:
//     bool operator()(pair<int , int>a , pair<int , int>b){
//         if(a.second > b.second) {
//             return true;
//         }else if(a.second == b.second){
//             return a.first > b.first;
//         }
        
//         return false;
//     }
// };

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