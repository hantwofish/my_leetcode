#include"../STLCOMMON.h"

using namespace std;


// 存储key 和值的入度
map<int,int> g_unMap;
vector<pair<int,int>> g_vecPair;

void PrintMap(map<int,int>& unMap)
{
    cout << " ---- unMap----" << endl;
    auto it = unMap.begin();
    while(it != unMap.end()){
        cout << it->first << " " << it->second << endl;
        g_vecPair.push_back(make_pair(it->first,it->second));
        it++;
    }
}

bool Cmp(pair<int,int>&A, pair<int,int>&B)
{
    if(A.second < B.second){
        return true;
    }else if(A.first < B.first){
        return true;
    }
    return false;
}

struct cmpBy{
    bool operator()(pair<int,int>&A, pair<int,int>&B)
    {
        return A.second < B.second;
    }
};

vector<int> tuperSort(vector<vector<int>>&nums)
{
    int src  =0 ;
    int dst = 0;
    for(int i = 0 ; i< nums.size(); i++){
        src = nums[i][0];
        dst = nums[i][1];
        if(g_unMap.find(src) == g_unMap.end()){ // 未找到
            g_unMap[src] = 0;
        }
        g_unMap[dst]++;

    }
    
    PrintMap(g_unMap);
    // / unMap 进行排序，先按照入度，后按照key 从小到大
    sort(g_vecPair.begin(),g_vecPair.end(),Cmp);

    deque<int> resu;
    

    


    return {};

}




int main()
{
    int N, rowNumber;
    vector<vector<int>> vec;
    cin>> N>> rowNumber;
    vec.resize(rowNumber,vector<int>(2,0));
    for(int i = 0; i< rowNumber; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        vec[i][0] = temp1;
        vec[i][1] = temp2;
    }

    // MyPrintTwo(vec);
    tuperSort(vec);


    cout << "end" << endl;
    return 0;
}