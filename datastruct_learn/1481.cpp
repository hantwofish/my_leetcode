#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class MyCompareMIN{
public:
    bool operator()(pair<int , int>a , pair<int , int>b){
        return a.second > b.second;
    }
};

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        for(int i= 0; i< arr.size(); i++){
            umap[arr[i]]++;
        }
        auto it = umap.begin();
        while(it != umap.end()){
            minQue.push({it->first, it->second});
            it++;
        }

        while(k > 0){
            int key = getMinKey();
            minQue.pop();
            if(umap[key] > k){
                umap[key] -= k;
                minQue.push({key, umap[key]});
                k -= k;
            }else if( umap[key] == k ){
                umap.erase(key);
                k -= k;
            }else{
                k -= umap[key];
                umap.erase(key);
            }

        }
        cout << "size= " << umap.size() << minQue.size()  << endl;
        return umap.size();
    }
    int getMinKey()
    {
        // int key = umap.begin()->first;
        // int val = umap.begin()->second;
        // auto it = umap.begin();
        // while(it != umap.end()){
        //     if(it->second < val){
        //         val = it->second;
        //         key = it->first;
        //     } 
        //     it++;
        // }
        // return key;
        auto  it = minQue.top();
        return it.first;

    }
private:    
    unordered_map<int,int>umap;
    priority_queue<pair<int,int>,vector<pair<int,int>>,MyCompareMIN>minQue; // 小顶堆
};

int main()
{
    Solution s1;
   vector<int>nums= {1,2,2,2,2};
   int k = 4;
   s1.findLeastNumOfUniqueInts(nums, k);

    

    cout << "hell22o" << endl;
    return 0;
}