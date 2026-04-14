#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void printInRange(struct Node* root, int low, int high) {
    if (root == NULL)
        return;

    if (root->data >= low)
        printInRange(root->left, low, high);

    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    if (root->data <= high)
        printInRange(root->right, low, high);
}

void freeTree(struct Node* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 17);
    insert(root, 4);
    insert(root, 18);
    insert(root, 2);
    insert(root, 9);

    int low = 4, high = 24;

    printInRange(root, low, high);
    printf("\n");

    freeTree(root);

    return 0;
}
