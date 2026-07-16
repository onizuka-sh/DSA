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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>nodes;
        unordered_set<int>childs;

        for(auto &it:descriptions){
            int parent=it[0];
            int child=it[1];
            int isLeft=it[2];

            // parent node is not yet made
            if(!nodes[parent]){
                nodes[parent]=new TreeNode(parent);
            }
            // child node is not yed made
            if(!nodes[child]){
                nodes[child]=new TreeNode(child);
            }

            if(isLeft){
                nodes[parent]->left=nodes[child];
            }
            else{
                nodes[parent]->right=nodes[child];
            }
            childs.insert(child);
        }
        TreeNode* root=NULL;
        // now find the root;
        for(auto &it:nodes){
            if(childs.find(it.first)==childs.end()){
                root=it.second;
                break;
            }
        }
        return root;
    }
};