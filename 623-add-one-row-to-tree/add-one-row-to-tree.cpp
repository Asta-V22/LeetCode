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
    void height(TreeNode* root, int val, int depth, int lvl){
        if(root==NULL){
            return;
        }
        lvl++;
        if(lvl==depth-1){//we have hit the point where we have to add the new nodes

                TreeNode* templeft = root->left;
                TreeNode* newleftNode = new TreeNode(val);
                root->left = newleftNode;
                newleftNode->left = templeft;



                TreeNode* tempright = root->right;
                TreeNode* newrightNode = new TreeNode(val);
                root->right = newrightNode;
                newrightNode->right = tempright;
            return;
        }
        height(root->left, val, depth, lvl);
        height(root->right, val, depth, lvl);


        
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //we'll approach this by using height of the tree at every node as our advantage
        if(depth==1){   //we need to change the root node 
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        TreeNode* head = root;
        int level = 0;
        height(root,val,depth,level);
        
        return head;
    }
};