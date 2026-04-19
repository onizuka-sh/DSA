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
 //the main thing is search for node's left in postorder and let that index to be index and then 
 // from l to index will be in left of node and from index +1 to  h will be in right;
class Solution {
public:

TreeNode* construct(vector<int>& pre,vector<int>& post,int & idx,int l,int r)
{
    if(idx>=pre.size() || l>r)
    return nullptr;
    TreeNode* root=new TreeNode(pre[idx++]);
    if(l==r)
    return root;
    int i=l;
    while(i<=r && (pre[idx]!=post[i]))
    {
        i++;
    }
    if(i<=r)
    {
        root->left=construct(pre,post,idx,l,i);
        root->right=construct(pre,post,idx,i+1,r-1);
    }
    return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int index=0;
        int r=preorder.size();
      return  construct(preorder,postorder,index,0,r-1);
    }
};