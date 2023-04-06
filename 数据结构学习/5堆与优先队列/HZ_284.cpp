#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<set>
#include<unordered_set>

#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;
typedef pair<int ,int >PII;
bool cmp1(PII& A, PII&B)
{
    if(A.second < B.second){
        return true;
    }else if( A.second == B.second){
        return A.first > B.first;
    }
    return false;
    
}
void Print(vector<pair<int,int>>& nums)
{
    int N= nums.size();
    cout << "-----------start-----------" << endl;
    for(int i = 0; i< N; i++){
        cout << nums[i].first << " " << nums[i].second << endl;
    }
    cout << "-----------end-----------" << endl;
}
void PrintMap(unordered_map<int,int>&mapl)
{
    cout << "-----------start-----------" << endl;
    auto it = mapl.begin();
    while (it != mapl.end())
    {
        cout << it->first << "| " << it->second << endl;
        it++;
    }
    cout << "-----------end-----------" << endl;

}

class Solution2{
public:
    int GetMainCost(int &N, vector<vector<int>>&data)
    {
        GetData(N,data);
        sort(nums.begin(),nums.end(),cmp1);
        // Print(nums);

        int total = 0;
        unordered_map<int,int>mapl;
        for(auto i : nums){
            mapl[i.second] = i.first;
        }

        // PrintMap(mapl);
        auto it = mapl.begin();
        while (it != mapl.end())
        {
           total += it->second;
           it++;
        }
        return total;
        
    }
    void GetData(int &N,vector<vector<int>>&data)
    {
        // cin>>N;
        // data.clear();
        // data.resize(N,vector<int>(2,0));
        // for(int i = 0; i < N; i++){
        //     int a, b;
        //     cin >> a >>b;
        //     data[i][0] = a;
        //     data[i][1] = b;
        // }
        for(int i =0 ; i< data.size();i++){
            nums.push_back({data[i][0], data[i][1]});
        }
        
    }

public:
    vector<pair<int,int>> nums;
};

class Solution{
public:
    int GetMainCost(int &N, vector<vector<int>>&data)
    {
        for(int i =0 ; i< data.size();i++){
            nums.push_back({data[i][0], data[i][1]});
        }
        sort(nums.begin(),nums.end(),cmp1);
        // Print(nums);
        int days = 0;
        int resu = 0;
        for(int i = 0; i< data.size(); i++){
            PII tmp = nums[i];
            // cout << "day= " << days << " temData= " << tmp.second << " value= " << tmp.first ;
            if(tmp.second > days){ // 在保质期内
                // cout << " ok";
                resu += tmp.first;
                days++;
            }
            // cout << endl;
        }

        return resu;
    }
public:
    vector<pair<int,int>> nums;

};

void GetDataInit(int &N,vector<vector<int>>&data)
{
    cin>>N;
    data.clear();
    data.resize(N,vector<int>(2,0));
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >>b;
        data[i][0] = a;
        data[i][1] = b;
    }

}

int main()
{

    int N= 7;
    vector<vector<int>>data = {
        {20 ,1},
        {2, 1},
        {10, 3},
        {100, 2},
        {8, 2},
        {10, 6},
        {10, 7},
        {5 ,20},
        {50 ,10},
        {11, 5},
        {12,5}
    };
    GetDataInit(N,data);
    Solution s1;
    int resu = s1.GetMainCost(N,data);
    cout  << resu << endl;



    return 0;
}

