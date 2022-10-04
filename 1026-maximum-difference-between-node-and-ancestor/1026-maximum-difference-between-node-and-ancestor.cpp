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
    int maxAncestorDiff(TreeNode* root, int mx = -1, int mn = -1) {
        if(root == NULL){
            return 0;
        }
        if(mx == -1){
            mx = mn = root -> val;
        }
        mx = max(mx, root -> val);
        mn = min(mn, root -> val);
        int ans = mx - mn;
        ans = max(ans, maxAncestorDiff(root -> left, mx, mn));
        ans = max(ans, maxAncestorDiff(root -> right, mx, mn));
        return ans;
    }
};