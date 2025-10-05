#include <stdio.h>
#include <stdlib.h>

// --- Tree Node Structure ---
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// --- Utility function to create a new node ---
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// --- Recursive Inorder Traversal Function ---
void inorderTraversal(Node* root) {
    // Base Case: If the current node is NULL, return.
    if (root == NULL) {
        return;
    }

    // 1. Recurse on the left subtree.
    inorderTraversal(root->left);

    // 2. Visit the current node (print its data).
    printf("%d ", root->data);

    // 3. Recurse on the right subtree.
    inorderTraversal(root->right);
}

// --- Main function to demonstrate the recursion ---
int main() {
    // Construct the tree:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder Traversal (Left -> Root -> Right): \n");
    inorderTraversal(root); // Output: 4 2 5 1 3
    printf("\n");

    // Note: In a complete program, you should also include a function
    // to free the dynamically allocated memory for the tree nodes.

    return 0;
}
