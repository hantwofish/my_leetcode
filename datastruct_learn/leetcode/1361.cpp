#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int i =0; i< leftChild.size(); i++){
            if(leftChild[i] ==  -1) continue;
            myMap[i].first++; // 出度
            myMap[leftChild[i]].second++; // 
        }
        for(int i= 0; i< rightChild.size();i++){
            if(rightChild[i] == -1) continue;
            myMap[i].first++; // 出度
            myMap[rightChild[i]].second++; // 
        }
        int zero_dif_num = 0;
        auto it = myMap.begin();
        while(it != myMap.end()){
            if(it->second.second == 0) zero_dif_num++;
            if(it->second.first > 1) return false; // 入度 > 1
            it++;
        }
        if(zero_dif_num == 0 || zero_dif_num > 1) return false;

        return true;
    }

private:
    unordered_map<int,pair<int,int>>myMap;
};  

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}