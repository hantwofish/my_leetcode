#include"../STLCOMMON.h"
using namespace std;

/*
采用并查集，将相邻的元素放入一个集合中
数据结构存储 (kefIndex, pair<node, nodeFather>)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        N = nums.size();
        cout << "N= " << N << endl;
        sort(nums.begin(),nums.end());
        input = nums;
        for(int i = 0; i< N; i++){
            auto it = make_pair(nums[i],nums[i]);
            unMap[i] = it;
        }
        cout << "-------------------------" <<endl;
        PrintMap(unMap);
        cout << "-------------------------" <<endl;

        // 进行遍历更新父节点
        for(int i = 1; i< N; i++){
            // 判断当前节点是否有相邻节点
            cout << "i = " << i << " i-1 = "<< i-1 << endl;
            if(nums[i] - nums[i-1] == 1 ){
                merge(i, i-1);
            }
            
        }
        
        PrintMap(unMap);

        // 最后遍历整个数组
        int maxValue = 0;
        for(int i = 0; i< N; i++){
            
            int fatherNode = findFather(unMap, i);
            cout << "findFather i= "  << i << " fatherNode= " << fatherNode <<  endl;
            resuMap[fatherNode]++;
            maxValue = max(maxValue, resuMap[fatherNode]);
        }

    
        return maxValue;

    }
    void PrintMap(unordered_map<int, pair<int,int>>& unMap)
    {
        cout << "++++++++++++++++++++++++++++" <<endl;
        auto it = unMap.begin();
        while(it != unMap.end()){
            cout << "key= " << it->first << " node= " << it->second.first << " node= " << it->second.second << endl;
            it++;
        }
        cout << "++++++++++++++++++++++++++++" <<endl;

    }

    int findFather(unordered_map<int, pair<int,int>> unMap, int m)
    {
        if(unMap[m].first == unMap[m].second){
            return unMap[m].first;
        }
        return findFather(unMap, unMap[m].second);
    }
    int merge(int m, int n)
    {
        
        if((n >= 0)&& (n < N)){
            
        }else{
            return 0;
        }
        // if(find(input.begin(), input.end(), input[n]) == input.end() ){
        //     return 0;
        // }
        cout << "merge m= " << m << " n= "<< n << endl; 

        int aa = findFather(unMap, m);
        cout << "merge aa= " << aa << endl;
        int bb = findFather(unMap, n);
        cout << "merge bb= " << bb << endl;
        cout << "merge m= " << m << " n= "<< n << " aa= " << aa << " bb=   " <<  bb <<  endl;
        if(aa == bb){
            return 0;
        }else{
            unMap[n].second = aa;
        }
        PrintMap(unMap);
        return 1;
    }
    
public:
    unordered_map<int, pair<int,int>> unMap;
    unordered_map<int,int> resuMap;
    vector<int> input;
    int N;
};

int main()
{
    Solution s1;
    vector<int>nums = {100,4,200,1,3,2};
    int resu = s1.longestConsecutive(nums);
    cout << "resu= " << resu << endl;
    cout << "---end---"<< endl;

}