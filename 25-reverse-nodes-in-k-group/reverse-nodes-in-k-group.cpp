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
    ListNode* reverse(ListNode *head,ListNode *ptr){
        ListNode *prev=NULL;
        ListNode *curr = head;
        ListNode *nxt= NULL;
        while(curr!=ptr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next==NULL){
            return head;
        }

        ListNode *ptr = head;
        int count = 0;
        while(ptr!=NULL && count<k){
            ptr = ptr->next;
            count++;
        }

        if(count<k){
            return head;
        }

        ListNode* newHead = reverse(head,ptr);
        head->next = reverseKGroup(ptr,k);
        return newHead;
    }
};