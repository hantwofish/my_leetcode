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
                j = i + 1;
                while (j < len && text[j] != ';') {
                    j++;
                }
                string temp = "";
                for (int k = i; k <= j; k++) {
                    temp += text[k];
                }
                if(mp.find(temp) ==  mp.end() ){
                    resu += temp;
                }else {
                    resu += mp[temp];
                }

                // cout << "temp= " << temp << " resu= " << resu << endl;

                i = j + 1;
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
    string str = "&&gt";
    string resu = s1.entityParser(str);
    cout << "resu=  " << resu << endl;

    return 0;
}   



