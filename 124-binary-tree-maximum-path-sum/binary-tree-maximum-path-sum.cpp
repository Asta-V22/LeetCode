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

    int maxPath(TreeNode* &node, int &maxi){
        if(node == NULL){
            return 0;
        }
        int lh = maxPath(node->left, maxi);
        int rh = maxPath(node->right, maxi);

        maxi = max(maxi , node->val + lh + rh);

        if(((node->val) + max(lh,rh))<0){
            return 0;
        } 
        else{
            return (node->val) + max(lh,rh);
        }
    }

    int maxPathSum(TreeNode* root) {
        int maxi =INT_MIN;
        maxPath(root, maxi);
        return maxi;

    }
};