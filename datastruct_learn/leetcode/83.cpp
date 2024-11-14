#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


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
    ListNode* deleteDuplicates(ListNode* head) {
        headNODE = head;
        ListNode* curnode = head;
        getallnodenum(headNODE);
        while(curnode != NULL){
            if(mymap[curnode->val] >= 2){
                cout << " urnode->val= " << curnode->val  << " " <<mymap[curnode->val] << endl; 
                delenodefunc(curnode);
                mymap[curnode->val]--;
                
            }
            curnode = curnode->next;

        }


        return headNODE;

    }
    void delenodefunc(ListNode* delenode)
    {
        if(delenode == headNODE){
            headNODE = delenode->next;
            return;
        }
        ListNode* prendoe = headNODE;
        while(prendoe->next != delenode){
            prendoe = prendoe->next;
        }
        prendoe->next = delenode->next;


    }
    void getallnodenum(ListNode* head)
    {
        ListNode* cur =head;
        while(cur!=nullptr){
            mymap[cur->val]++;
            cur = cur->next;
        }

          auto it = mymap.begin();
        while(it != mymap.end()){
            cout << it->first << " " << it->second << endl;
            it++;
        }

        
    }
private:    
    ListNode* headNODE;
    unordered_map<int,int>mymap;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}