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
public:
    
    TreeNode* first = nullptr, *second = nullptr, *previous = new TreeNode(-1000000001);
    void dfs(TreeNode* root){

        if(root == nullptr) return;
       
        dfs(root->left);
        
        if(first == nullptr && previous->val > root->val && previous->val != -1000000001){
            first = previous;
        }
        
        if(first != nullptr && previous->val > root->val){
            second = root;
        }
        previous = root;
        
        dfs(root->right);
    }
    
    void recoverTree(TreeNode* root) {
      
        dfs(root);
        swap(first->val, second->val);
        
    }
};