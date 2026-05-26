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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode dummy;
        ListNode* mergedList = &dummy;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                mergedList->next = temp1;
                temp1=temp1->next;
            }
            else{
                mergedList->next = temp2;
                temp2=temp2->next;
            }
            mergedList=mergedList->next;
        }
        


            if(temp1!=NULL){
                mergedList->next=temp1;
            }
            else{
                mergedList->next=temp2;
            }
            return dummy.next;
        }
};