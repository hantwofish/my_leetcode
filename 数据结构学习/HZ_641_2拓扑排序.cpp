#include"../STLCOMMON.h"

using namespace std;

// 定义一个三元组，分别为 key, 入度，指向的数组
vector<tuple<int,int, vector<int>>> g_vec;
map<int, pair<int,vector<int>>>g_map;
vector<int>g_resu;

bool Cmp(tuple<int,int, vector<int>>&A, tuple<int,int, vector<int>>&B)
{
    if(get<1>(A) < get<1>(B) ){
            return true;
    }else if(get<0>(A) < get<0>(B)){
        return true;
    }
    return false;
}

void solve(vector<vector<int>>&nums)
{
    for(int i = 0; i< nums.size(); i++){
        int temp1 =nums[i][0];
        int temp2 =nums[i][1];
        // 先初始化
        g_map[temp1].first = 0;
        g_map[temp1].second = {};
    }
    for(int i = 0; i< nums.size(); i++){
        int temp1 =nums[i][0];
        int temp2 =nums[i][1];
        g_map[temp1].second.push_back(temp2);
        g_map[temp2].first = g_map[temp2].first + 1;
    }
    auto it = g_map.begin();
    while(it != g_map.end()){
        g_vec.push_back(make_tuple(it->first, it->second.first, it->second.second));
        it++;
    }

    sort(g_vec.begin(),g_vec.end(),Cmp);
    while(!g_vec.empty()){
        auto vecFirst = g_vec[0];
        g_resu.push_back(get<0>(vecFirst));
        

    }

}


void GET_DATA(int &N, int& rowNumber, vector<vector<int>>& vec)
{
    cin>> N>> rowNumber;
    vec.resize(rowNumber,vector<int>(2,0));
    for(int i = 0; i< rowNumber; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        vec[i][0] = temp1;
        vec[i][1] = temp2;
    }
}

int main()
{
    int N = 7, rowNumber = 6;
    vector<vector<int>> vec = {
            {1, 2},
            {1, 4},
            {2, 3},
            {4, 5},
            {3, 6},
            {5, 6},
            };
    // GET_DATA(N,rowNumber,vec);


    MyPrintTwo(vec);


    cout << "end" << endl;
    return 0;
}