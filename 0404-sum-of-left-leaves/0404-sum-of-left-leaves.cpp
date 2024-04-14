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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode * node=p.first;
            int level=p.second;
            if(node->left!=NULL){
                q.push({node->left,level+1});
                if(node->left->left==NULL && node->left->right==NULL){
                sum+=node->left->val;
                }
            }
            if(node->right!=NULL){
                q.push({node->right,level+1});
            }
        }
        return sum;
    }
};