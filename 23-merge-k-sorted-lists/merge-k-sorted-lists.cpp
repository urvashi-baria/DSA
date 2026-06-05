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
    ListNode* mergeTwoSortedLists(ListNode *left,ListNode* right){
        if(left ==NULL)
            return right;
        if(right == NULL)
            return left;
        if(left->val < right->val){
             left->next = mergeTwoSortedLists(left->next,right);
             return left;
        
        } else{
            right->next = mergeTwoSortedLists(left,right->next);
            return right;
        }
    }
    ListNode* mergeSort(vector<ListNode*>& arr,int low,int high){
        if(low == high){
            return arr[low];
        }
        int mid = low+(high-low)/2;
        ListNode* left = mergeSort(arr,low,mid);
        ListNode* right = mergeSort(arr,mid+1,high);
        return mergeTwoSortedLists(left,right);
        
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if(lists.size()==0){
        return NULL;
      }  
      return mergeSort(lists,0,lists.size()-1);
    }
};