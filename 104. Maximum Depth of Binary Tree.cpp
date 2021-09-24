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
    
    int dfs(TreeNode* node){
        if(node -> left == NULL && node -> right == NULL){
            return 0;
        }
        int ans = 0;
        if(node -> left != NULL){
            ans = max(ans, 1 + dfs(node -> left));
        }
        if(node -> right != NULL){
            ans = max(ans, 1 + dfs(node -> right));
        }
        return ans;
    }
    
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return dfs(root) + 1;
    }
};
