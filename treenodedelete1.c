#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a BST node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to find the minimum value node in a BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node to be deleted found

        // Case 1: No child or only one child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Two children
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform an inorder traversal of the BST and save to file
void inorderTraversal(struct Node* root, FILE* file) {
    if (root != NULL) {
        inorderTraversal(root->left, file);
        fprintf(file, "%d ", root->data);
        inorderTraversal(root->right, file);
    }
}

// Function to generate random numbers within a range and save to file
void generateRandomNumbers(int lower, int upper, int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    srand(time(NULL));  // Initialize random number generator

    for (int i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        fprintf(file, "%d ", num);
    }

    fclose(file);
    printf("Random numbers generated and saved to file: %s\n", filename);
}

// Function to read numbers from a file and build a BST
struct Node* buildBSTFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }

    struct Node* root = NULL;
    int num;

    while (fscanf(file, "%d", &num) != EOF) {
        root = insertNode(root, num);
    }

    fclose(file);
    return root;
}

// Driver program to test the BST deletion and random number generation
int main() {
    const char* inputFilename = "input.txt";
    const char* outputFilename = "output.txt";
    const int lowerLimit = 1;
    const int upperLimit = 100;
    const int numCount = 10;

    // Generate random numbers and save to input file
    generateRandomNumbers(lowerLimit, upperLimit, numCount, inputFilename);

    // Build BST from input file
    struct Node* root = buildBSTFromFile(inputFilename);

    // Perform BST operations (e.g., delete a node)
    // ...

    // Open output file for writing
    FILE* outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error opening file: %s\n", outputFilename);
        return 1;
    }

    // Perform inorder traversal and save to output file
    inorderTraversal(root, outputFile);

    // Close output file
    fclose(outputFile);
    printf("BST traversal saved to file: %s\n", outputFilename);

    return 0;
}
