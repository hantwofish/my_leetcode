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

class Trie {
public:
    Trie() {

    }
    
    void insert(string word) {
        mySet.insert(word);
    }
    
    bool search(string word) {
        if(mySet.find(word) != mySet.end()){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        auto it = mySet.begin();
        while(it != mySet.end()){
            string str = *it;
            int index = str.find(prefix);

            if(index == 0 ){
                return true;
            }
            it++;
        }
        return false;
    }
public:
    unordered_set<string>mySet;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    // Solution s1;
    

    cout << "hello" << endl;
    return 0;
}