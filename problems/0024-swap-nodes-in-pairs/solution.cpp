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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return head;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* pre=&dummy;
        while(pre->next!=nullptr and pre->next->next!=nullptr){
            ListNode* cur=pre->next;
            ListNode* n=cur->next;

            cur->next=n->next;
            n->next=cur;
            pre->next=n;

            pre=cur;
        }return dummy.next;
    }
};
