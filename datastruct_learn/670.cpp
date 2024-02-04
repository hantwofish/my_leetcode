#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class MyCompareMAX{
public:
    bool operator()(pair<char , int>a , pair<char , int>b){
        return a.first < b.first;
    }
};

class Solution2 {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        for(int i = 0; i< str.length(); i++){
            maxQue.push(make_pair(str[i], i));
        }
        for(int i = 0; i< str.length(); i++){
            char tempChar = str[i];
            if( maxQue.top().first > str[i]){
                str[i] = maxQue.top().first;
                str[maxQue.top().second] = tempChar;
                maxQue.pop();
                break;
            }else{
                maxQue.pop();
            }
        }
        int resu = stoi(str);
        return resu;
    }
private:    
    priority_queue<pair<char,int>,vector<pair<char,int>>,MyCompareMAX>maxQue;// 大顶堆
};

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        string resu = str;
        for(int i =0; i< str.length();i++){
            for(int j = i+1; j < str.length(); j++){
                string str_temp = str;
                swap(str_temp[i],str_temp[j]);
                if(str_temp > resu){
                    resu = str_temp;
                }

            }
        }

        return stoi(resu);
    }
};

int main()
{
    Solution s1;
    int num = 1993;
    int resu = s1.maximumSwap(num);

    

    cout << "resu " << resu <<  endl;
    return 0;
}