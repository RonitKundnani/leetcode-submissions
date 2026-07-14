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
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr and fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* middle=nullptr;
        if(fast!=nullptr){
            //even number no middle element
            middle=slow->next;
        }else{
            //middle element exist
            middle=slow;
        }
        ListNode* prev=nullptr;
        ListNode* next=nullptr;
        ListNode* cur=middle;
        while(cur!=nullptr){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        middle=prev;
        while(middle!=nullptr){
            if(middle->val!=head->val) return false;
            middle=middle->next;
            head=head->next;
        }return true;
    }
};
