/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 0-> didn't find any
 1-> found left
 2-> found right
 */
class Solution {
public:
    
    TreeNode *ans = nullptr;
    
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(root == nullptr || ans != nullptr) return 0;
        
        int foundp = 0, foundq = 0;
        
        int left = dfs(root->left, p, q);
        int right = dfs(root->right, p, q);
        
        if(left == 1 || right == 1 || root == p) foundp = 1;
        if(left == 2 || right == 2 || root == q) foundq = 1;
        
        if(foundp && foundq){
            ans = root;
            return 0;
        }
        
        if(foundp) return 1;
        if(foundq) return 2;
        return 0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        dfs(root, p, q);
        return ans;
    }
};