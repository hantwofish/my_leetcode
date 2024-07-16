#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;


/*

1. 存储每个邮箱地址和人名直接对应的 哈希表
2. 将每个邮箱都赋予一个 标号，进行 合并
3. 合并后每个邮箱属于同一个组。
4. 根据同一个组的任意一个邮箱找到人名，进行和邮箱合并成一个 vector

*/



class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        set<string>emailSet;
        unordered_map<string, string> emailMapName;
        for(int i = 0; i < accounts.size(); i++){
            string name = accounts[i][0];
            for(int j = 1; j < accounts[i].size(); j++){
                emailMapName[accounts[i][j]] =  name;
                emailSet.insert(accounts[i][j]);
            }
        }
        
        // 存储邮箱与 邮箱数字的哈希 邮箱数字与邮箱的hash
        unordered_map<string , int>emainIndexHash;
        unordered_map<int , string >indexEmailHash;
        auto it = emailSet.begin();
        int index = 0;
        while(it != emailSet.end()){
            emainIndexHash[*it] =  index;
            indexEmailHash[index] = *it;
            it++;
            index++;
        }


        // 并查集合并
        UnionFind U1(emailSet.size());
        for(int i = 0; i < accounts.size(); i++){
            int start =  emainIndexHash[accounts[i][1]];
            for(int j = 1; j < accounts[i].size(); j++){
                int end = emainIndexHash[accounts[i][j]];
                U1.unionNode( start, end ) ;
            }
        }

        unordered_map<int, vector<string>> fatehString;
        // 找到father 
        for(int i = 0; i < emailSet.size(); i++){
            int father  = U1.find_fa(i);
            string name =  emailMapName[ indexEmailHash[father] ];
            string email = indexEmailHash[i];
            fatehString[father].push_back(email);
            cout << " father= " <<  father << " " << name << " -> " << email << endl;
        }

        vector<vector<string>>resu;
        auto it2 = fatehString.begin();
        while(it2 != fatehString.end()){
            string name = emailMapName[ indexEmailHash[it2->first] ];
            vector<string> temp;
            temp.push_back(name);
            for(auto i : it2->second){
                temp.push_back(i);
            }
            resu.push_back(temp);

            it2++;
        }
        
        for(int i = 0; i < resu.size(); i++){
            for(int j = 0; j < resu[i].size(); j++){
                cout << resu[i][j] << " ";
            }
            cout << endl;
        }



        
        
        return {};
    }
private:
   
  



};

int mainFunc()
{
    Solution s1;
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, 
    {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
     {"Mary", "mary@mail.com"}};
    s1.accountsMerge(accounts);
    return 0;
}

int main()
{

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}