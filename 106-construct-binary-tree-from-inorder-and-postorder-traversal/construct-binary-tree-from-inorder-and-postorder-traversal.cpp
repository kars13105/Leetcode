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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty())
            return NULL;
        int n = postorder.size();
        TreeNode* root = new TreeNode(postorder[n-1]);

        vector<int> left;
        vector<int> right;

        bool f = true;

       
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == postorder[n-1]) {
                f = false;
                continue;
            }

            if (f)
                left.push_back(inorder[i]);
            else
                right.push_back(inorder[i]);
        }

        vector<int> lefts;
        vector<int> rights;

        f = true;

        
        for (int i = n-2; i >= 0; i--) {
            
            if (rights.size() == right.size())
                f = false;

            if (f)
                rights.push_back(postorder[i]);
            else
                lefts.push_back(postorder[i]);
        }
        reverse(lefts.begin(), lefts.end());
        reverse(rights.begin(), rights.end());

        root->left = buildTree(left, lefts);
        root->right = buildTree(right, rights);

        return root;
    }
};