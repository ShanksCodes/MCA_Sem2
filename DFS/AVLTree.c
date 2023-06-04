#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Node* root = NULL;

int isEmpty();
struct Node* insertNode(struct Node*, int);
struct Node* deleteNode(struct Node*, int);
int searchElement(struct Node*, int);
void inorderTraversal(struct Node*);
void preorderTraversal(struct Node*);
void postorderTraversal(struct Node*);
int max(int, int);
int getHeight(struct Node*);
int getBalance(struct Node*);
struct Node* rotateRight(struct Node*);
struct Node* rotateLeft(struct Node*);
struct Node* minValueNode(struct Node*);

int main() {

    int element = 0;
    int choice = 0;
    int size = -1;
    int pos = 0;

    do {

        printf("\n----------------------------------------------------------\n\n");
        printf("1. Press 1 for insertion into AVL Tree.\n");
        printf("2. Press 2 for preorder traversal.\n");
        printf("3. Press 3 for inorder traversal.\n");
        printf("4. Press 4 for postorder traversal.\n");
        printf("5. Press 5 for deletion from AVL Tree.\n");
        printf("6. Press 8 to search an element in AVL Tree:\n");

        printf("-1. Press -1 to exit.\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("\nInsertion into AVL Tree...\n");
            printf("Enter element to insert: ");
            scanf("%d", &element);
            root = insertNode(root, element);
            break;

        case 2:
            printf("\nPreoder traversal of AVL Tree:\n");
            if (isEmpty()) {
                printf("\nTree is empty!");
                break;
            }
            preorderTraversal(root);
            printf("\n----Root Value(testing): %d\n", root->data);
            break;

        case 3:
            printf("\nInorder traversal of AVL Tree:\n");
            if (isEmpty()) {
                printf("\nTree is empty!");
                break;
            }
            inorderTraversal(root);
            printf("\n----Root Value(testing): %d\n", root->data);
            break;

        case 4:
            printf("\nPostorder traversal of AVL Tree:\n");
            if (isEmpty()) {
                printf("\nTree is empty!");
                break;
            }
            postorderTraversal(root);
            printf("\n----Root Value(testing): %d\n", root->data);
            break;

        case 5:
            printf("\nDeletion from AVL Tree...\n");
            if (isEmpty())
                printf("\nTree is empty!");
            else {
                printf("\nEnter element to delete: ");
                scanf("%d", &element);
                root = deleteNode(root, element);
                printf("\n----Root Value(testing): %d\n", root->data);
            }
            break;

        case 6:
            if (isEmpty()) {
                printf("\nTree is empty!");
                break;
            }
            printf("\nEnter element to search in the tree: ");
            scanf("%d", &element);
            if (searchElement(root, element))
                printf("\nElement found in the tree");
            else
                printf("\nElement not found in the tree");
            break;

        case -1:
            break;
        default:
            printf("\nInvalid entry!");

        }

        if (choice != -1) {
            printf("\n\nPress any key to continue...");
            getch();
        }

    } while (choice != -1);


    printf("\n----------------------------------------------------------\n\n");
    return 0;
}

int isEmpty() {
    return (root == NULL);
}

struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else
        return node; // Duplicate found

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorderTraversal(struct Node* node) {
    if (node == NULL)
        return;

    inorderTraversal(node->left);
    printf("%d -> ", node->data);
    inorderTraversal(node->right);
}

void preorderTraversal(struct Node* node) {
    if (node == NULL)
        return;

    printf("%d -> ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(struct Node* node) {
    if (node == NULL)
        return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d -> ", node->data);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

struct Node* rotateRight(struct Node* node) {
    struct Node* leftChild = node->left;
    struct Node* leftRightChild = leftChild->right;

    leftChild->right = node;
    node->left = leftRightChild;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    leftChild->height = 1 + max(getHeight(leftChild->left), getHeight(leftChild->right));

    return leftChild;
}

struct Node* rotateLeft(struct Node* node) {
    struct Node* rightChild = node->right;
    struct Node* rightLeftChild = rightChild->left;

    rightChild->left = node;
    node->right = rightLeftChild;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    rightChild->height = 1 + max(getHeight(rightChild->left), getHeight(rightChild->right));

    return rightChild;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

int searchElement(struct Node* node, int data) {
    if (node == NULL)
        return 0;

    if (data == node->data)
        return 1;

    if (data < node->data)
        return searchElement(node->left, data);

    return searchElement(node->right, data);
}
