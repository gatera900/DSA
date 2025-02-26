#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Inorder Traversal Function (Left -> Root -> Right)
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);   // Visit left subtree
    cout << root->val << " ";       // Print root node
    inorderTraversal(root->right);  // Visit right subtree
}

// Driver Code
int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
