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
    void reorderList(ListNode *head)
    {
        if (head->next==nullptr or head->next->next==nullptr)//edge case
        {
            return;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while (fast!=nullptr and fast->next!=nullptr)//find middle
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* second=slow->next;//reverse the second half
        slow->next=nullptr;
        ListNode* prev=nullptr;
        ListNode* mid=second;
        ListNode* next=nullptr;
        while (mid!=nullptr)
        {
            next=mid->next;
            mid->next=prev;
            prev=mid;
            mid=next;
        }
        second=prev; 

        while (second!=nullptr)//reorder now
        {
            ListNode* ftemp=head->next;
            ListNode* stemp=second->next;
            head->next=second;
            second->next=ftemp;
            head=ftemp;
            second=stemp;
        }
    }
};
