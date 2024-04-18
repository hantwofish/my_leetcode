#include"../STLCOMMON.h"

using namespace std;

/*
set 不可包含重复元素，自动排序
*/

class PointCmp{
public:
    bool  operator()(const pair<int,int> &A, const pair<int,int> &B) const // const 不可少, 对于Pair需要将多种情况都讨论
    {
        if(A.first < B.first){
            return true;
        }else if(A.first == B.first) {
            return A.second < B.second;
        }
        
        return  false;
    }
};


// set 自定义排序
class SetOrde{
public:
    void init()
    {
        mySet.insert({1,2});
        mySet.insert({3,0});
        mySet.insert({2,-1});
        mySet.insert({3,1});
        PrintSet(mySet);
        // mySet.erase({1,2});
        // PrintSet(mySet);
    }
    void testSetOrder()
    {   
        auto deleteNum = make_pair(1,2);
        auto it = mySet.find(deleteNum);
        if(it != mySet.end()){
            cout << "found" << endl;
        }else{
            cout << "NOT found" << endl;
        }


        


    }
    void PrintSet(set<pair<int,int>,PointCmp>&mySet)
    {
        cout << "-----------start------------"<< endl;
        auto it = mySet.begin();
        while (it != mySet.end()){
            cout << it->first << " " << it ->second << endl;
            it++;
        }  
        cout << "-----------start------------" << endl;

    }
    void FindKey()
    {
        auto it = mySet.find({1,1});
        if(it != mySet.end()){
            cout << "found" << endl;
        }else{
            cout << "NOT found" << endl;
        }

    }
    void EraseKEy()
    {

        mySet.erase({15,16});
    }


public:
    set<pair<int,int>,PointCmp>mySet;
};


class SetOne{
public:
    void init()
    {
        mySet.insert(1);
        mySet.insert(2);
        mySet.insert(3);        
        mySet.insert(-1);
        PrintSet(mySet);
        mySet.erase(1);
        PrintSet(mySet);
    }
    void testSetOrder()
    {      


        


    }
    void PrintSet(set<int>&mySet)
    {
        cout << "-----------start------------"<< endl;
        auto it = mySet.begin();
        while (it != mySet.end()){
            cout << *it << endl;
            it++;
        }  
        cout << "-----------start------------" << endl;

    }
    void FindKey()
    {
        auto it = mySet.find(1);
        if(it != mySet.end()){
            cout << "found" << endl;
        }else{
            cout << "NOT found" << endl;
        }

    }
    void EraseKEy()
    {

        mySet.erase(1);
    }


public:
    set<int>mySet;
};

int main()
{
    // test();
    SetOrde s1;
    s1.init();
    s1.testSetOrder();
    return 0;
}

        //不能使用sa.erase(3)，这样会删除sa中所有的元素3。
    //应当找到指向3的迭代器，然后删除这个迭代器，代码如下。
    // auto it = sa.find(3);
    // if (it != sa.end()) sa.erase(it);
    
    // for (auto it = sa.begin(); it != sa.end(); it++) {
    //     cout << *it << endl;
    // }