#include"../STLCOMMON.h"
using namespace std;

/*
采用并查集，将相邻的元素放入一个集合中
数据结构存储 (kefIndex, pair<node, nodeFather>)
*/

class Union {
public:
    Union(int N) : n(N){
        fa.resize(n, 0);
        size.resize(n,0);
    }

public:
    void init()
    {
        for(int i = 0; i < n; i++){
            fa[i] = i;
            size[i] = 1;
        }
    }
    int find(int x)
    {
        if(fa[x] == x){
            return x;
        }
        return find(fa[x]);
    }
    int merge(int x, int y)
    {
        int xx  = find(x);
        int yy = find(y);
        if(xx == yy){
            return 0;
        }
        fa[xx] = yy; // 把 xx 挂到 yy 上
        size[yy] += size[xx];
        return 1;
    }
    void PrinVec(vector<int>&fa)
    {
        for(int i = 0 ; i< fa.size(); i++){
            printf("%3d", i);
        }
        printf("\n");

        for(int i = 0 ; i< fa.size(); i++){
            printf("---");
        }
        printf("\n");

        for(int i = 0 ; i< fa.size(); i++){
            printf("%3d", fa[i]);
        }
        printf("\n");
    }

public:
    int n;
    vector<int>fa;
    vector<int>size;


};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int N = nums.size();
         cout << "inde= aaa" << endl;
        

        Union uNion(N);
        uNion.init();
        uNion.PrinVec(uNion.fa);


        unordered_map<int, int> unMap; // <value, 下标>
        cout << "inde= xxx" << endl;
        int index = 0;
        for(int i = 0 ; i < N; i++){
            int x = nums[i];
            if(unMap.find(x) != unMap.end()){
                continue;
            }
            unMap[x] = index;
            index++;
            if(unMap.find(x+1) != unMap.end()){
                uNion.merge(unMap[x], unMap[x+1]);
            }
            if(unMap.find(x-1) != unMap.end()){
                uNion.merge(unMap[x], unMap[x-1]);
            }
        }
        uNion.PrinVec(uNion.fa);
        // 在并查集中找出集合最多的集合
        int ans = 0;
        for(int i = 0; i < N; i++){
            ans = max(ans, uNion.size[i]);
        }

        return ans;
        

    }
    
};

int main()
{
    Solution s1;
    cout << "start" << endl;
    vector<int>nums = {100,4,200,1,3,2};
    int resu = s1.longestConsecutive(nums);
    cout << "resu= " << resu << endl;


    deque<int> deq;
    deq.po
    cout << "---end---"<< endl;

}