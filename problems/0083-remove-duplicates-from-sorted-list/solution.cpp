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
        if (head == nullptr or head->next==nullptr) return head;
        ListNode* n= head;
        while(n->next!=nullptr){
            if(n->val==(n->next)->val){
                ListNode* t=n->next;
                n->next=t->next;
                delete t;
            }else{
                n=n->next;
            }
        }
        return head;
    }
};
