#include"../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<set>
#include<unordered_set>

#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>
#include <iterator>

using namespace std;
class Solution{
public:
    string entityParser(string text)
    {
        init();
        int len = text.length();
        int i = 0;
        int j = 0;
        string resu = "";
        while ( i < len) {
            if (text[i] == '&') {
                // 判断后面 4 5 67 个字符是不是 要替换的，是则替换，不是则保持
                string str4= "";
                string str5 = str4;
                string str6 = str4;
                string str7 = str4 ;
                if(i + 4  -1< len){
                    str4 = text.substr(i, 4);
                }
                if(i + 5  -1< len){
                    str5 = text.substr(i, 5);
                }
                if(i + 6  -1< len){
                    str6 = text.substr(i, 6);
                }
                if(i + 7  -1< len){
                    str7 = text.substr(i, 7);
                }
                cout <<"i= " << i <<  " " << str4 << " |  " << str5 << " | " << str6 << " | " << str7 << endl;

                if( mp.find(str4) != mp.end()){
                    resu += mp[str4];
                    i+=4;

                }else if( mp.find(str5) != mp.end()){
                    resu += mp[str5];
                    i+=5;

                }else if( mp.find(str6) != mp.end()){
                    resu += mp[str6];
                    i+=6;
                
                }else if( mp.find(str7) != mp.end()){
                    resu += mp[str7];
                    i+=7;
                }else{
                    resu += text[i];
                    i++;
                }
                
            } else {
                resu += text[i];
                i++;
            }
          
            cout << "resu= " << resu << endl;
        }

        return resu;
    }
    void init()
    {
        mp.insert({"&quot;","\""});
        mp.insert({"&apos;","\'"});
        mp.insert({"&amp;","&"});
        mp.insert({"&gt;",">"});
        mp.insert({"&lt;","<"});
        mp.insert({"&frasl;","/"});
    }



public:
    unordered_map<string,string>mp;
};

int main()
{
    Solution s1;
    string str = "1&&gt;";
    string resu = s1.entityParser(str);
    cout << "2sresu=  " << resu << endl;

    return 0;
}   





