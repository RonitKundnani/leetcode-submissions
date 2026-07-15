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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* f=head;
        ListNode* s=head;
        ListNode* newHead=nullptr;
        ListNode* prevtail=nullptr;
        while(f!=nullptr){ //outer loop for iterating over list
            f=s;
            for(int n = 1;n<k and f!=nullptr;n++){ //inner loop to point f to desired node (after k elements)
                f=f->next;
            }
            if(f==nullptr) break; //for case when remaining elements exist which need not to reverse

            ListNode* rest=f->next; //storing rest List's pointer
            f->next=nullptr; //seperating k group of elems to reverse

            ListNode* prev=nullptr;
            ListNode* cur=s;
            ListNode* next=nullptr;
            while(cur!=nullptr){
                next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
            ListNode* x=prev;
            if(prevtail==nullptr){newHead=x;}
            else{prevtail->next=x;}
            prevtail=s;
            s->next=rest;
            s=rest;
        }
        return newHead;
    }
};
