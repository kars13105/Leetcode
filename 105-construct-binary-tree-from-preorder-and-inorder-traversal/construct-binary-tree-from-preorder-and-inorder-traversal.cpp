class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if (preorder.empty())
            return NULL;

        TreeNode* root = new TreeNode(preorder[0]);

        vector<int> left;
        vector<int> right;

        bool f = true;

       
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
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

        
        for (int i = 1; i < preorder.size(); i++) {
            
            if (left.size() == lefts.size())
                f = false;

            if (f)
                lefts.push_back(preorder[i]);
            else
                rights.push_back(preorder[i]);
        }

        root->left = buildTree(lefts, left);
        root->right = buildTree(rights, right);

        return root;
    }
};