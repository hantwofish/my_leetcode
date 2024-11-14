#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class WordDictionary_2 {
public:
    WordDictionary_2() {
        wordTree.resize(2, vector<int>(26, 0));
        total_num = 1;

        end.resize(100, false);
    }
    
    void addWord(string word) {
        int start_row = 1;
        for(int i = 0; i< word.size(); i++){
            int num = word[i] - 'a';
            if(wordTree[start_row][num] == 0){
                wordTree[start_row][num] = total_num +1; 
                total_num++;   
                wordTree.push_back(vector<int>(26,0));         
            }
            start_row = wordTree[start_row][num];
            
        }
        end[start_row] = true;
        

        MyPrintTwo(wordTree);
        cout << "end= " << start_row << endl;
    }
    

    bool search(string word)
    {
        bool flga= false;
        for(auto &i : resu){
            if(search_2(i)){
                return true;
            }
        }
        return false;
    }

    void dfs(const string ori_str, int N, string &cur, int index)
    {
        if(cur.length() == N){
            cout << "curstr= " << cur << endl;
            resu.push_back(cur);
            return;
        }
        if(ori_str[index] != '.'){
            cur += ori_str[index];
            dfs(ori_str, N, cur, index + 1);
            return;
        }else{
            for(int i = 0; i< 26; i++){
                cur += ( i + 'a');
                // cout << "idnex= " << index << " i= " << i << " cur= "<< cur << endl;
                dfs(ori_str, N, cur, index+1);
                cur.pop_back();
            }
        }
    }



    bool search_2(string word) {
        int len = word.length();
        int p =1;
        for(int i = 0; i < len; i++){
            int ch = word[i]-'a';
            p = wordTree[p][ch];
            if( p == 0){
                return false; // 在中间则不相同，返回false;
            }
        }

        return end[p]; // 判断是否结尾相同全词匹配。
    }
private:
    vector<vector<int>>wordTree;
    vector<bool>end; // 长度为多少
    int total_num;
    vector<string>resu;
};  

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class WordDictionary {
public:
    WordDictionary() {

    }
    
    void addWord(string word) {
        mySet.insert(word);
    }
    
    bool search(string word) {
        resu.clear();
        string temp ="";
        dfs(word, word.size(), temp, 0);
        for(int i= 0; i < resu.size(); i++){
            if(mySet.find(resu[i]) != mySet.end()){
                return true;
            }
        }
        return false;
    }
public:
    void dfs(const string ori_str, int N, string &cur, int index)
    {
        if(cur.length() == N){
            cout << "curstr= " << cur << endl;
            resu.push_back(cur);
            return;
        }
        if(ori_str[index] != '.'){
            cur += ori_str[index];
            dfs(ori_str, N, cur, index + 1);
            return;
        }else{
            for(int i = 0; i< 26; i++){
                cur += ( i + 'a');
                // cout << "idnex= " << index << " i= " << i << " cur= "<< cur << endl;
                dfs(ori_str, N, cur, index+1);
                cur.pop_back();
            }
        }
    }
private:
    vector<string>resu;
    set<string>mySet;

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main()
{
    cout << "hell22o start" << endl;
    WordDictionary s1;
//    s1.addWord("bike");
//    s1.addWord("bin");
//    s1.addWord("yes");
//    s1.addWord("bikea"); 
    string temp = "c.ad";
    string resu = "";
    s1.dfs(temp ,temp.size(),resu, 0);
      
    

    cout << "hell22o" << endl;
    return 0;
}