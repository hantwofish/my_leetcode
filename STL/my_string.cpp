#include"STLCOMMON.h"

using namespace std;


// 查找子串, 151翻转字符串
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
            index = totalStr.find(str,position); // 从postin 处查找子串
            cout << "index= " <<  index << endl;
            indexVec.push_back(index);
        }
        position = index + str.size();
    }

    return indexVec;
}
// 输出所有子串
void printAllSubstr(string &str)
{
    for(int start = 0; start < str.length(); start++){
        for(int length = 1; length <= str.length()- start; length++){
            int endindex = start + length -1;
            cout << str.substr(start, length) << " " << "endindex= " << endindex << endl;
        }
    }
}

int main()
{
    string totalStr = "asdaasdassd";
    string str = "sd";
    test_find(totalStr, str);

    return 0;
}