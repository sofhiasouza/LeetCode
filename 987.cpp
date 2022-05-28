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
    
    void dfs(TreeNode* p, int r, int c, vector < pair < int, pair < int, int > >> &nodes)
    {
        nodes.push_back({c, {r, p->val}});
        
        if(p->left) dfs(p->left, r+1, c-1, nodes);
        if(p->right) dfs(p->right, r+1, c+1, nodes);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector < pair < int, pair < int, int > > > nodes;
        
        dfs(root, 0, 0, nodes);
    
        sort(nodes.begin(), nodes.end());
        
        vector<vector<int>>ans;
        
        
        vector < int > aux;
        aux.push_back(nodes[0].second.second);
        int prev = nodes[0].first;
        for(int i = 1 ; i < nodes.size() ; i++){
            
            if(nodes[i].first != prev){
                ans.push_back(aux);
                aux.clear();
                prev = nodes[i].first;
            }
            aux.push_back(nodes[i].second.second);
        }
        ans.push_back(aux);
        
        return ans;
    }
};