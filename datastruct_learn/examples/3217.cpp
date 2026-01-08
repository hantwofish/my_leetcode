#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // 头部新添加一个节点 vaL =-1;
        ListNode* node_head = new ListNode(-1);
        node_head->next = head;
        ListNode* new_head = node_head;
        print_list(new_head);

        for(int i = 0; i < nums.size(); i++){
            new_head = delete_ele(new_head, nums[i]);
            // new_head = delete_ele(new_head, 2);
        }
        
        
        
        // print_list(new_head);
        ListNode* delete_head = new_head;
        ListNode* actual_head = new_head->next;
        print_list(actual_head);
        delete(delete_head);

        return actual_head;
    }
    ListNode* delete_ele(ListNode* head, int delete_val)
    {
        ListNode* cur_prd = head;
        ListNode* cur_Ptr = head->next;    
        while (cur_Ptr != nullptr) {
            /* code */
            if(cur_Ptr->val == delete_val){ // delete it
                
                ListNode* delete_Node =cur_Ptr;
                cur_prd->next = cur_Ptr->next;
                cur_Ptr = cur_Ptr->next;
                
                delete(delete_Node);
            }else{
                cur_prd = cur_Ptr;
                cur_Ptr = cur_Ptr->next;
                // cur_bid = cur_Ptr->next;
            }
        }
        return head;
    }

    ListNode* print_list(ListNode* head){
        ListNode* cur_head = head;
        while(cur_head != nullptr){
            cout << cur_head->val << " -> " ;
            cur_head = cur_head->next;
        }
        cout << " null " << endl;
    }
};

int main()
{
    Solution S1;
    vector<int>nums ={1,2,3};
    vector<int>heas_nums = {1,2,3,4,5};
    ListNode* head = nullptr;
    ListNode* cur_Node = head;
    for(int i = 0; i < heas_nums.size(); i++){
        if(i == 0){
            head = new ListNode(heas_nums[i]);
            cur_Node= head;
        }else{
            cur_Node ->next = new ListNode(heas_nums[i]);
            cur_Node = cur_Node->next;
        }
        
    }
    // S1.print_list(head);
    S1.modifiedList( nums, head);
    // S1.print_list(head);

   cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe