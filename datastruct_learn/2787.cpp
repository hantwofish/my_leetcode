
#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> resu ;
        for (int i = 0; i < words.size(); i++) {
            if(words[i].size() == 1 && words[i][0] == separator) continue;
            splitString(words[i], separator, resu);
        }

        return resu;
    }
    void splitString(string str, char separator_2, vector<string>& result)
    {
        int cur_Index  = 0;
        if(str[0] == separator_2){
            str = str.substr(1, str.length()-1);
        }
        int lenth = str.length();
        if(str[lenth -1] != separator_2){
            str += separator_2;
        }
        cout << "str= " << str << endl;

        int index = str.find(separator_2, cur_Index);
        cout << "inde= " << index << endl;
        while(index != string::npos){
            string str_temp = str.substr(cur_Index, index -cur_Index);
            cout << str_temp  << endl;
            if(str_temp.length() > 0){
                result.push_back(str_temp);
            }
            cur_Index = index +1;
            index = str.find(separator_2, cur_Index);
        }
    }
};
int main()
{
    Solution s1;
    vector<string> str=  {"#","#"};
    char separator = '#';
    s1.splitWordsBySeparator(str, separator);

    

    cout << "hell22o2" << endl;
    return 0;
}