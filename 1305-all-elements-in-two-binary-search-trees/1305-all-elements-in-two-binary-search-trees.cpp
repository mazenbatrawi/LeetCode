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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        function<void(TreeNode*)> get = [&] (TreeNode* root){
            if(root == NULL){
                return;
            }
            ans.push_back(root -> val);
            get(root -> left);
            get(root -> right);
        };
        get(root1);
        get(root2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};