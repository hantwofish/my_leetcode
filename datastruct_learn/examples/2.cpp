#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
// #include "../INCLUDE/TREE.h"

using namespace std;

/**/
//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 =  stol( str_reverse (list_2_str(l1)) );
        int num2 =stol( str_reverse (list_2_str(l2)) );
        int sum_val = num1 + num2;
        string val = to_string(sum_val);


        ListNode * root = string_2_list(str_reverse(val));
        return root;
    }
public:    
    string str_reverse(string val)
    {
        string valval = "";
        for(int i = 0 ; i< val.size(); i++){
            valval = val[i] + valval;
        }
        return valval;
    }
    ListNode* string_2_list(string str)
    {
        ListNode* root = new ListNode(str[0] - '0');;
        ListNode* cur = root;

        for(int i = 1; i < str.size();i++){
            ListNode *temp = new ListNode(str[i] - '0');
            cur->next = temp;
            cur = cur->next;
        }
        return root;
    }
    string list_2_str(ListNode* root)
    {
        ListNode* cur = root;
        string str = "";
        while(cur != nullptr){
            cout << cur->val << endl;
            str += (cur->val - 0 + '0');
            cur = cur->next;
        }
        cout << endl;
        cout << "str= " << str << endl;
        return str;
    }
};

int main()
{
    Solution s1;

    ListNode* root = s1.string_2_list("243");
    string str = s1.list_2_str(root);

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp