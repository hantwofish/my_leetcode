#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;


#define N 26
struct TrieNode {
    TrieNode* children[N];
    bool isWordEnd;
};

class Trie {
public:
    Trie() {
        root = createNode();
    }
    ~Trie(){
        Free(root);
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(int i = 0; i< word.size(); i++){
            char temp = word[i];
            if( cur->children[temp - 'a'] == nullptr ){ // 没有这个节点
                cur->children[temp-'a'] = createNode();
                cur = cur->children[temp-'a'];
            }else{ // 有这个节点
                cur = cur->children[temp-'a'];
            }
            if( i == word.size()-1 ){
                cur->isWordEnd = true;
            }
        }
        return;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(int i = 0; i< word.size(); i++){
            char temp = word[i];
            if(cur->children[temp - 'a'] == nullptr){
                return false;
            }
            cur = cur->children[temp - 'a'];
            if(i == word.size()-1 && cur->isWordEnd == true){
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i = 0; i< prefix.size(); i++){
            char temp = prefix[i];
            if(cur->children[temp - 'a'] == nullptr){
                return false;
            }
            cur = cur->children[temp - 'a'];
        }
        return true;
    }
    TrieNode* createNode()
    {
        TrieNode* root = new TrieNode();
        cout << "new " << endl;
        for(int i = 0; i< N; i++){
            root->children[i] = nullptr;
        }
        root->isWordEnd = false;
        return root;

    }
    void Free(TrieNode* root)
    {
        if(root == nullptr) return;
        for(int i = 0; i< N; i++){
            if(root->children[i]){
                Free(root->children[i]);
            }
        }
        free(root);
        cout << "free " << endl;

    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */ 

int main()
{
    // Trie* obj = new Trie();
    Trie obj;
    obj.insert("abcdcfg");
    cout << "hell22o" << endl;
    return 0;
}