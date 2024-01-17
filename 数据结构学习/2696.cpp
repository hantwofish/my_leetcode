#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minLength(string s) {
        while(s.find("AB") != string::npos && s.find("CD") != string::npos ){
            int index = s.find("AB");
            if(s.find("AB") != string::npos){
                s.erase(index,index+ 2);
            }
            index = s.find("CD");
            if(index != string::npos){
                s.erase(index, index+2);
            }
        }
        return s.length();
        
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}