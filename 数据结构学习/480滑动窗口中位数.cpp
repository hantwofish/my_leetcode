#include"../STLCOMMON.h"

using namespace std;


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long long> muSet;
        for(int i =0 ; i< k ; i++){
            muSet.insert(nums[i]);
        }
        resu.push_back(GetMiddleNum(muSet));

        for(int i = k;  i< nums.size(); i++){
            // 删除开头元素
            auto it = muSet.find(nums[i -k ]);
            muSet.erase(it);

            muSet.insert(nums[i]);
            resu.push_back(GetMiddleNum(muSet));

        }

        return resu;
    }
    double GetMiddleNum(multiset<long long>& muSet)
    {
        int N = muSet.size() -1 ;
        int index = 0;
        
        if(N % 2 == 0){
            index =  N /2;
            auto it =muSet.begin();
            std::advance(it, index);
            return *it;
        }
        int index2 = (N +1) / 2;
        // index = (N +1) / 2- 1;

        // auto fornt = muSet.begin();
        // std::advance(fornt, index);

        auto behind = muSet.begin();    
        std::advance(behind, index2);

        return (*prev(behind, 1) + *behind )/2.0;

        // res.push_back((*mid + *prev(mid, (1 - k % 2))) / 2);
    }
private:
    vector<double>resu;
};

int main()
{
    Solution s1;
    vector<int>nums= {1,4,2,3};
    int k =4;
    vector<double> resu = s1.medianSlidingWindow(nums, k);
    MyPrintOne(resu);



    cout << "--end---" << endl;
    return 0;

}