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
    int getCount(ListNode* head){
        ListNode* temp = head;
        int count= 0 ;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int idx = getCount(head)-n;
        if(idx==0){
            return head->next;
        }
        ListNode* t = head;
        for(int i = 1;i<idx;i++){
            t=t->next;
        }
        t->next=t->next->next;
        return head;
    }
};