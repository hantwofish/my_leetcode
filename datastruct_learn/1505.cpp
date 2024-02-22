#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    string minInteger(string num, int k) {
        for(int i= 0; i< num.size(); i++){
            numMap[num[i]].push_back(i);
        }
        while(k > 0){
            char num_val = numMap.begin()->first;
            vector<int> numVec = numMap.begin()->second;
            sort(numVec.begin(),numVec.end());
            int num_Index = numVec[0];
            numVec.erase(numVec.begin());

            char sort_vla = 


        }


    }
private:
    map<char,vector<int>>numMap;
};  

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}