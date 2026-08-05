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
    TreeNode* righty(TreeNode* root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    TreeNode* helper(TreeNode* root){
        //we have three cases
        //1. The node at which our key was only has right side
        if(root->left==NULL){   //now lets assume if we had root->right==NULL also then it will reurn root->right(which will be null) so that also works out
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* rightSide = root->right;
        TreeNode* rightmost = righty(root->left);
        rightmost->right = rightSide;
        TreeNode* temp = root->left;
        delete root;

        return temp;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;

        if(root->val==key) return helper(root);

        //store root for the returning purposes
        TreeNode* dummy = root;

        while(root!=NULL){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left = helper(root->left); //this helper function will care about all the rearrangements
                    break;
                }
                else{
                    //doubt: What happens if the root->left becomes null and we don't get our answer??
                    root = root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->val==key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return dummy;


    }
};