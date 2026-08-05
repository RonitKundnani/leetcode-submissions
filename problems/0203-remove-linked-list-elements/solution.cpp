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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* n=new ListNode();
        n->val=-1;
        n->next=head;
        ListNode* t=n;
        while((t->next)!=nullptr){
            if((t->next)->val==val){
                ListNode* temp=t->next;
                t->next=temp->next;
                delete temp;
            }
            else{
                t=t->next;
            }
        }
        return n->next;
    }
};
