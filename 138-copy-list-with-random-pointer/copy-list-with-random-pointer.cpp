/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* newHead = new Node(head->val);
        Node* currOld = head->next;
        Node* currNew = newHead;
        
        while(currOld!=NULL){
            currNew->next= new Node(currOld->val);
            currNew=currNew->next;
            currOld=currOld->next;
        }
        
        unordered_map<Node*, Node*>m;
        Node* tempa = head;
        Node* tempb = newHead;
        while(tempa!=NULL){
            m[tempa]=tempb;
            tempa=tempa->next;
            tempb=tempb->next;
        }
        
        tempa = head;
        tempb = newHead;
        while(tempa!=NULL){
            tempb->random=m[tempa->random];

            tempa=tempa->next;
            tempb=tempb->next;
        }
        return newHead;
    }
};