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
    pair<int,int> func(TreeNode* node, int count, int sum, int &total){
        if(node==nullptr){
            return {0,0};
        }

        auto [sum_left, count_left] = func(node->left, count, sum, total);
        auto [sum_right, count_right] = func(node->right, count, sum, total);
        int nodesum = sum_left + sum_right + node->val;
        int nodecount = count_left + count_right + 1;
        if(nodesum/nodecount==node->val) total++;
        return {nodesum,nodecount};

    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        int sum = 0;
        int total= 0;
        func(root, count, sum, total);
        return total;
    }
};