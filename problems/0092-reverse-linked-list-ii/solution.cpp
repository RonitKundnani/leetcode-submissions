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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right or head->next==nullptr) return head;
        ListNode D(0);
        ListNode* t=&D;
        t->next=head;
        ListNode* cur=head;
        for(int i=0;i<left-1;i++){
            t=cur;
            cur=cur->next;
        }ListNode* prev=nullptr;
        for(int i=0;i<right-left+1;i++){
            ListNode* tempNext=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tempNext;
        }
        t->next->next=cur;
        t->next=prev;
        return D.next;
    }
};
