#include"../STLCOMMON.h"

using namespace std;

#define NUMBER 100
#define N  27
int g_trie[N][N] = {0};
int g_nodeNumber = 0; // 记录总的节点个数总节点个数 100
bool g_flag[NUMBER] = {0};



class Solution {
public:
    string longestWord(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            makeTrie(words[i]);
        }
        


        return "";
    }
    void makeTrie(string str)
    {
        int parent = 0;
        bool flag1 = 0; // 代表是否是子串的结束
        for(int i = 0; i< str.size(); i++){
            int j = str[i] - 'a' + 1;
            if(g_trie[parent][j] == 0){
                g_trie[parent][j] = g_nodeNumber + 1;
                g_nodeNumber++;
                flag1 = false;
            }else{
                flag1 = true;
            }
            parent = g_trie[parent][j];
        }
        if(flag1 ){
            cout << "flag1 " << parent <<endl;
            g_flag[parent] = true;
        }else{
            g_flag[g_nodeNumber] = true;
            cout << "flag1 " << g_nodeNumber <<endl;
        }
        
    }

    void PrintInfo()
    {
        for(int i = 0 ; i< N; i++){
            for(int j = 0; j < N ; j++){
                cout << g_trie[i][j] << " ";
        }
        cout << endl;
        }
        for(int i = 0; i < NUMBER; i++){
            cout << g_flag[i] << " ";
        }
        cout << endl;

    }

};



int main()
{
    vector<string> words= {"cat","banana","dog","nana","walk","walker","dogwalker"};
    Solution s1;
    string resu = s1.longestWord(words);
    cout << "resu=" << resu << endl;
    cout << "hello" << endl;
    s1.longestWord(words);
    s1.PrintInfo();





    return 0;
}