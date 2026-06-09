/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void inorder(TreeNode*root,vector<TreeNode*> &arr){
        if(root == nullptr) return;
        inorder(root->left,arr);
        arr.push_back(root);
        inorder(root->right,arr);
    }
    TreeNode* binarySearch(vector<TreeNode*> &arr,int low,int high){
        if(low>high){
            return nullptr;
        }
        int mid = low+(high-low)/2;
        arr[mid]->left = binarySearch(arr,low,mid-1);
        arr[mid]->right = binarySearch(arr,mid+1,high);
        return arr[mid];
        
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> arr;
        inorder(root,arr);
        return binarySearch(arr,0,arr.size()-1);
   }
};