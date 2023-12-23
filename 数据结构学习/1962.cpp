#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        for(int i = 0; i< piles.size(); i++){
            que.push(piles[i]);
        }
        while(k > 0){
            int topval  = que.top();
            que.pop();
            int left = topval - (topval / 2);
            que.push(left);
            k--;
        }
        int resu = 0; 
        while(!que.empty()){
            resu += que.top();
            que.pop();
        }
        cout << "resu= " << resu << endl;
        return resu;

    }
public: 
    priority_queue<int> que; // 默认大顶堆
};

int main()
{
    Solution s1;
    vector<int> piles = {5,4,9};
    int k = 2;
    s1.minStoneSum(piles,k);

    

    cout << "hell22o" << endl;
    return 0;
}