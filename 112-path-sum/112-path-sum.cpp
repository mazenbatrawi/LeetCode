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
    
    bool visited[5005];
    
    bool dfs(TreeNode* node, int x, int now){
        if(node -> left == NULL && node -> right == NULL && now == x){
            return 1;
        }
        bool ans = 0;
        if(node -> left != NULL){
            ans |= dfs(node -> left, x, now + node -> left -> val);
        }
        if(node -> right != NULL){
            ans |= dfs(node -> right, x, now + node -> right -> val);
        }
        return ans;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        return dfs(root, targetSum, root -> val);
    }
};