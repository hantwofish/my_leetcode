#include"../STLCOMMON.h"
using namespace std;

#define uint32 unsigned int

typedef  struct{
    int x;
    int y;
    int height;
}node;

struct rule{ // 按照结构体中 先按照 height 从大到小，再按照 x 从小到大
    bool operator()(node a, node b){  // 方法1 重载()，当为 ture 的时候进行交换
        if(a.height < b.height) {
            return true;
        }else if(a.height == b.height){
            return a.x > b.x;
        }else {
            return false;
        }
        return false;

        // if(a.height == b.height){
        //     return a.x > b.x;
        // }
        // return a.height < b.height;
        
    }
};



class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        startLocation = buildings[0][0];
        endLocation = buildings[0][1];

        priority_queue<node,vector<node>,rule> preQue;
        for(int i = 0; i < buildings.size(); i++){
            startLocation = min(startLocation, buildings[i][0]);
            endLocation = max(endLocation, buildings[i][1]);

            node temp = {buildings[i][0],buildings[i][1],buildings[i][2]};
            preQue.push(temp);
        }

        vector<int> eleme(endLocation + 2 , 0);
 
        while(!preQue.empty()){
            cout << preQue.top().x << " " << preQue.top().y << " " << preQue.top().height << endl;
            int i= preQue.top().x;
            int j = preQue.top().y;
            int heigh = preQue.top().height;
            for(int cur= i ; cur <= j; cur++){
                if(eleme[cur] == 0){
                    eleme[cur] = heigh;
                }
            }

            preQue.pop();
        }

        cout << "start= " << startLocation << " end= " << endLocation << endl;
        MyPrintOne(eleme);
        for(int i = 0; i< eleme.size()-1; i++){
            if(eleme[i] > eleme[i+1]){
                eleme[i] = eleme[i+1];
            }
        }
        MyPrintOne(eleme);
        vector<vector<int>>resu;
        resu.push_back({startLocation,eleme[startLocation] });
        for(int i = startLocation; i< eleme.size()-1; i++){
            if(eleme[i +1 ] != eleme[i]){
                cout << "i =" << i+1 <<  " val= " << eleme[i+1] << endl;
                resu.push_back({i+1,eleme[i+1] });
            }
        }


        return resu;
    }
public:
    int startLocation;
    int endLocation;
};

int main()
{
    Solution s1;
    vector<vector<int>> buildings = {
        {2,9,10},
        {3,7,15},
        {5,12,12},
        {15,20,10},
        {19,24,8}};
    vector<vector<int>> resu =s1.getSkyline(buildings);
    cout << "end" << endl;
    
    return 0;
}