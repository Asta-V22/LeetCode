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
private:
    TreeNode* buildnewTree(vector<int>& preorder, vector<int>& inorder, int start, int end,int n, int &i){
        if(start>end){
            return NULL;
        }
        int newroot = preorder[i];
        i++;
        //now we need to find this root inside inorder
        int j;
        
        for(int k=0; k<n; k++){
            if(inorder[k]==newroot){
                j = k;
                break;
            }
        }
        TreeNode* root = new TreeNode(newroot);;
        root->left = buildnewTree(preorder, inorder, start , j-1,n,i);
        root->right = buildnewTree(preorder, inorder, j+1, end,n,i);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int start = 0;
        int end = n-1;

        int i = 0;

        return buildnewTree(preorder, inorder, start, end,n,i);
    }
};