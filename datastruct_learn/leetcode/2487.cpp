#include"../STLCOMMON.h"
#include"../COMMONALO.h"
using namespace std;
/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* top = head;
        ListNode* curnode = head;
        bool flag =0;
        while(curnode != nullptr){
            // 判断右侧是否有比当前节点大的节点
            ListNode* cur = curnode;
            flag = 0;
            while(cur != nullptr){
                if(cur->val > curnode->val){
                    flag = true;
                    break;
                }
            }
            if(flag == true){
                // 如果为头
                if(curnode == top){
                    top = curnode->next;
                }else{
                    
                }

            }else{
                curnode = curnode->next;
            }
        }
        return top;
        
    }
};






int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}