#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for each node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        // Create a new node if the tree is empty
        return createNode(data);
    }

    // Recursively insert nodes based on their values
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to perform inorder traversal of the BST and store the nodes in a file
void inorderTraversal(struct Node* root, FILE* file) {
    if (root != NULL) {
        inorderTraversal(root->left, file);
        fprintf(file, "%d ", root->data);
        inorderTraversal(root->right, file);
    }
}

// Function to perform preorder traversal of the BST and store the nodes in a file
void preorderTraversal(struct Node* root, FILE* file) {
    if (root != NULL) {
        fprintf(file, "%d ", root->data);
        preorderTraversal(root->left, file);
        preorderTraversal(root->right, file);
    }
}

// Function to perform postorder traversal of the BST and store the nodes in a file
void postorderTraversal(struct Node* root, FILE* file) {
    if (root != NULL) {
        postorderTraversal(root->left, file);
        postorderTraversal(root->right, file);
        fprintf(file, "%d ", root->data);
    }
}

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    struct Node* root = NULL;
    int numNodes, minValue, maxValue;

    srand(time(NULL)); // Initialize the random number generator

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the minimum value: ");
    scanf("%d", &minValue);

    printf("Enter the maximum value: ");
    scanf("%d", &maxValue);

    // Open files for writing the traversal results
    FILE* inorderFile = fopen("inorder.txt", "w");
    FILE* preorderFile = fopen("preorder.txt", "w");
    FILE* postorderFile = fopen("postorder.txt", "w");

    for (int i = 0; i < numNodes; i++) {
        int data = generateRandomNumber(minValue, maxValue);
        root = insertNode(root, data);
    }

    // Perform the traversals and store the results in respective files
    inorderTraversal(root, inorderFile);
    preorderTraversal(root, preorderFile);
    postorderTraversal(root, postorderFile);

    // Close the files
    fclose(inorderFile);
    fclose(preorderFile);
    fclose(postorderFile);

    printf("Traversal results stored in files: inorder.txt, preorder.txt, postorder.txt\n");

    return 0;
}
