#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node *insert(struct Node *node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct Node *root, FILE *output) {
    if (root != NULL) {
        fprintf(output, "%d ", root->data);
        preOrder(root->left, output);
        preOrder(root->right, output);
    }
}

int main() {
    FILE *output = fopen("output.txt", "w");

    if (output == NULL) {
        printf("Failed to open the output file.\n");
        return 1;
    }

    struct Node *root = NULL;
    int lower_limit = 1;
    int upper_limit = 20;
    int num_elements = 11;

    // Generate random numbers and insert them into the AVL tree
    srand(time(NULL));
    int i;
    for (i = 0; i < num_elements; i++) {
        int data = (rand() % (upper_limit - lower_limit + 1)) + lower_limit;
        root = insert(root, data);
    }

    printf("Preorder traversal of the constructed AVL tree: ");
    preOrder(root, stdout);
    printf("\n");

    fprintf(output, "Preorder traversal of the constructed AVL tree: ");
    preOrder(root, output);

    fclose(output);

    return 0;
}
