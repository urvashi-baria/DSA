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
    ListNode* getMid(ListNode* head){
       ListNode* slow = head;
       ListNode* fast = head->next;
       while(fast!=NULL && fast->next != NULL){
           slow= slow->next;
           fast= fast->next->next;
       }
       return slow;
    }

    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }

            tail=tail->next;
        }

        if(list1!=NULL){
            tail->next = list1;
        }
        else if(list2!=NULL){
            tail->next = list2;
        }

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        //to divide
        ListNode* mid = getMid(head);
        ListNode* rightHalf = mid->next;
        mid->next = NULL;

        //to sort
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHalf);

        //merge
        return merge(left,right);
    }
};