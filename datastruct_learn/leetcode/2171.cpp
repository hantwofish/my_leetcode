#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
/*
最后剩下的值一定为原先数组中的一个值
对于大于的，需要移除差值
对于小于的，需要全部移除
*/

class Solution { 
public:
    long long minimumRemoval(vector<int>& beans) {
        long long resu = INT32_MAX;
        long long temp = 0;
        sort(beans.begin(),beans.end());
        long long total_sum = 0;
        for(int i= 0; i< beans.size(); i++){
            total_sum += beans[i];
        }
        
        for(int i= 0; i< beans.size(); i++){
            temp = 0;
            temp = total_sum - (beans.size()-i) * beans[i];

            
            cout << "i= " << i << " temp= " << temp << endl;
            resu = min(resu,temp);
        }
        return resu;
        
    }
};

class Solution2 { // 超时
public:
    long long minimumRemoval(vector<int>& beans) {
        long long resu = INT32_MAX;
        long long temp = 0;
        for(int i= 0; i< beans.size(); i++){
            temp = 0;
            for(int j= 0; j < beans.size(); j++){
                if(i ==j ) continue;
                if(beans[j] > beans[i]){
                    temp += (beans[j]-beans[i]);
                }else if(beans[j] < beans[i]){
                    temp +=  beans[j];
                }

            }
            cout << "i= " << i << " temp= " << temp << endl;
            resu = min(resu,temp);
        }
        return resu;
        
    }
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    vector<int>beans = {4,1,6,5};
    int resu = s1.minimumRemoval(beans);
    cout << "resu= " << resu << endl;
    

    cout << "hell22o" << endl;
    return 0;
}