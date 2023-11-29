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

class Solution {
public:
    int countPoints(string rings) {
        if(rings.size() <= 2) return 0;
        for(int i =1; i< rings.size(); i = i +2){
            char rig = rings[i-1];
            char num = rings[i];
            // cout << "num= " << num  << " ring= " << rig << endl;
            u_int8_t val = 0;
            if(rig == 'R') {
                // cout << "rig==r" << endl;
                val = (val | 0x01);
            }else if(rig == 'G'){
                // cout << "rig==g" << endl;
                val = (val | 0x02);
            }else if (rig == 'B') {
                // cout << "val= " << val << endl;
                val = (val | 0x04u);
                // cout << "rig==  b" <<  " val= " << val << endl;
            }
            cout << "i= " << i << " val= " << val << endl;
            if(mymap.find(num) == mymap.end()){
                mymap.insert({num, val});
            }else{
                val = val | mymap[num];
                mymap[num] = val;
            }
            // cout << "num= " << num << " val= " << mymap[num] << endl;
        }
        int  resu = 0;
        auto it = mymap.begin();
        while(it != mymap.end()){
            if(it->second == 0x07){
                resu++;
            }
            it++;
        }
        return resu;
        
    }

public:
    unordered_map<char,u_int8_t>mymap;
};



int main()
{
    Solution s1;
    string str= "B0B6G0R6R0R6G9";
    int resu = s1.countPoints(str);
    cout << "resu= " << resu << endl;
    
    return 0;
}