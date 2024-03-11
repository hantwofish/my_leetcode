#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int A_num = 0;
        int B_num = 0;
        for(int i= 0; i< secret.length(); i++){
            if(secret[i] == guess[i]){
                A_num++;
            }else{
                u_map[secret[i] - '0']++;
                u_map_guess[guess[i] - '0']++;
            }
        }
        auto it = u_map_guess.begin();
        while(it != u_map_guess.end()){
            int key_num = it->first;
            B_num += min(u_map[key_num],u_map_guess[key_num]);
            it++;
        }

        string resu = "";
        resu =  resu + to_string(A_num) + "A" + to_string(B_num) + "B";
        cout << "resu= "<< resu <<endl;
        return resu;
    }
private:
    unordered_map<int,int>u_map;
    unordered_map<int,int>u_map_guess;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    string secret = "1123";
    string guess = "0111";
    s1.getHint(secret, guess);
    

    cout << "hell22o" << endl;
    return 0;
}