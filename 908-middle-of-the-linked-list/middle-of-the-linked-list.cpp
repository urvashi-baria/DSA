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
       int count = 0;
       while(temp!=NULL){
         count++;
         temp=temp->next;
       } 
       return count;
    }
    ListNode* middleNode(ListNode* head) {
       int idx = getCount(head)/2;
       ListNode* temp = head;
       for(int i = 0;i<idx;i++){
           temp = temp->next;
       } 
       return temp;
    }
};