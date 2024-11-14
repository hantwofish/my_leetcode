#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class DataStream {
public:
    DataStream(int value, int k) 
    {
        VALUE = value;
        K = k;
    }

    bool consec(int num)
    {
        vec.push_back(num);
        if (vec.size() < K) {
            return false;
        }
        // 如果上次是 true ,且新加的数为 val 则一定最后K 个是val return true;
        if(flag == true && num == VALUE){
            return true;
        }else{
            flag = false;
        }
        int tempK = K;
        int endIndex = vec.size() - 1;
        while (tempK > 0) {
            if (vec[endIndex] != VALUE) {
                return false;
            }
            tempK--;
            endIndex--;
        }
        flag = true;
        return true;
    }

private:    
    vector<int>vec;
    int VALUE;
    int K ;
    bool flag = false;
}; 

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

int main()
{
    long long num = 0;
    long long minNum =  -1 * ( (long long)1 << 32);
    long long maxNum = (long long)1 << 32;
    cout << minNum << endl;
    cout << maxNum << endl;
    
    cout << "hell22o" << endl;
    return 0;
}