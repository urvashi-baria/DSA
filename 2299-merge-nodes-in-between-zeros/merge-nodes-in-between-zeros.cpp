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
    ListNode* mergeNodes(ListNode* head) {
        if(head->next == NULL){
            return head;
        }
        int sum  = 0;
        ListNode dummy;
        ListNode* ptr = &dummy;
        while(head->next){
            sum+=head->val;
            head=head->next;
            if(head->val==0){
               ptr->next = new ListNode(sum);
               sum=0;
               ptr = ptr->next;
            }
        } 
        ptr->next = NULL;
        return dummy.next;        
    }
};