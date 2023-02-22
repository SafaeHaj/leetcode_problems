#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive approach with global variable
vector<int> tree;
vector<int> recursive_preorderTraversal(TreeNode *root) {
    if (root == nullptr)
        return tree;
    
    tree.push_back(root->val);
    recursive_preorderTraversal(root->left);
    recursive_preorderTraversal(root->right);
}

vector<int> iterative_preorderTraversal(TreeNode *root)
{
    // Morris Traversal approach
    vector<int> tree;
    TreeNode *node = root;

    while (node != nullptr)
    {

        if (node->left == nullptr)
        {
            tree.push_back(node->val);
            node = node->right;
        }

        else
        {
            TreeNode *subroot = node->left;

            while (subroot->right && subroot->right != node)
            {
                subroot = subroot->right;
            }

            if (subroot->right == nullptr)
            {
                tree.push_back(node->val);
                subroot->right = node;
                node = node->left;
            }

            else
            {
                subroot->right = nullptr;
                node = node->right;
            }
        }
    }

    return tree;
}