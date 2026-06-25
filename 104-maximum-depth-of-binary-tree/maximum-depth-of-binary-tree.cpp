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
    int maxDepth(TreeNode* root) {

        int height=0;
        if(root == NULL) return height;

        queue<TreeNode*> st;

        st.push(root);
        while(!st.empty()){
            height++;
            int size = st.size();

            for(int i=0; i<size; i++){
                TreeNode* temp = st.front();
                st.pop();
                if(temp->left != NULL) st.push(temp->left);
                if(temp->right != NULL) st.push(temp->right);
            }

        }

        return height;
    }
};