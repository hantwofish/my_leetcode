#include"STLCOMMON.h"

using namespace std;



vector<int> test_find(string totalStr, string str)
{
    vector<int>indexVec;
    int position = 0;
    int index = 0;
    while( position  < totalStr.size()){
        cout << "position= " << position <<  endl;
        if(totalStr.find(str,position) == string::npos){
            return indexVec;
        }else{
            // 从position 处开始查找
            index = totalStr.find(str,position);
            cout << "index= " <<  index << endl;
            indexVec.push_back(index);
        }
        position = index + str.size();
    }

    return indexVec;
}

int main()
{
    string totalStr = "asdaasdassd";
    string str = "sd";
    test_find(totalStr, str);

    return 0;
}