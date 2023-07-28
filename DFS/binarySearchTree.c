#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node*root=NULL;

int isEmpty();
struct Node* insertion(struct Node*, int);
struct Node* minValueNode(struct Node*);
struct Node* deletion(struct Node*, int); 
int searchElement(struct Node*, int);
void inorderTraversal(struct Node*ptr);
void preorderTraversal(struct Node*ptr);
void postorderTraversal(struct Node*ptr);
void levelOrderTraversal(struct Node*ptr);

int main()
 {
    
    int element =0;
    int choice=0;
    int size=-1;
    int pos=0;
  
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to for insertion into Binary Search Tree.\n");
    printf("2. Press 2 for preorder traversal.\n");
    printf("3. Press 3 for inorder traversal.\n");
    printf("4. Press 4 for postorder traversal.\n");
    printf("5. Press 5 for deletion Binary Search Tree.\n");
    printf("6. Press 8 to search an element in binary tree:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       
       case 1: printf("\nInsertion into binary search tree...\n");
                printf("Enter element to insert: ");
                scanf("%d", &element);
                root = insertion(root, element);
                break;

       case 2: printf("\nPreoder treversal of tree:\n");
               if(isEmpty())
                {
                  printf("\nTree is empty!");
                  break;
                }
               preorderTraversal(root);
               printf("\n----Root Value(testing): %d\n",root->data);
               break;

       case 3: printf("\nInorder treversal of tree:\n");
               if(isEmpty())
                {
                  printf("\nTree is empty!");
                  break;
                }
               inorderTraversal(root);
               printf("\n----Root Value(testing): %d\n",root->data);
               break;
       
       case 4: printf("\nPostoder treversal of tree:\n");
               if(isEmpty())
                {
                  printf("\nTree is empty!");
                  break;
                }
               postorderTraversal(root);
               printf("\n----Root Value(testing): %d\n",root->data);
               break;      
      
       case 5: printf("\nDeletion in binary tree...\n");
               if(isEmpty())
                printf("\nTree is empty!");
               else
                { 
                   printf("\nEnter element to delete: ");
                   scanf("%d",&element);
                   root = deletion(root, element);
                   printf("\n----Root Value(testing): %d\n",root->data);
                }
               break;
            

       case 6: if(isEmpty())
                {
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

       case -1: break;
       default: printf("\nInvalid entry!");    
                             
     }

       if(choice!=-1)
        {
          printf("\n\nPress any key to continue...");
          getch();
        }

   }while(choice!=-1);

   
    printf("\n----------------------------------------------------------\n\n");
    return 0;
 }


  int isEmpty()
    {
      return (root==NULL);
    }

/*
                       4
                     /   \
                    2     6
                   / \   / \
                  1   3 5   7
*/
   
struct Node* insertion(struct Node* root, int data)
 {
    if (root == NULL) 
     {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
     }

    if (data < root->data) 
        root->left = insertion(root->left, data);
    
    else if (data > root->data) 
        root->right = insertion(root->right, data);
    
    return root;
 }


void levelOrderTraversal(struct Node* root) {
    // Create a queue using an array to keep track of the nodes
    struct Node* queue[100];
    int front = -1;
    int rear = -1;

    // Enqueue the root node to start traversal from it
    queue[++rear] = root;

    while (front != rear) {
        // Dequeue a node and process it
        struct Node* currentNode = queue[++front];
        printf("%d -> ", currentNode->data);

        // Enqueue the left child if it exists
        if (currentNode->left) {
            queue[++rear] = currentNode->left;
        }

        // Enqueue the right child if it exists
        if (currentNode->right) {
            queue[++rear] = currentNode->right;
        }
    }
}

  void preorderTraversal(struct Node*ptr)
  {     
    
    if(ptr==NULL)
      return;
          
    printf("%d -> ", ptr->data);  
    preorderTraversal(ptr->left);
    preorderTraversal(ptr->right); 
      
  } 

void inorderTraversal(struct Node* ptr) 
 {
    if (ptr == NULL)
        return;

    inorderTraversal(ptr->left);
    printf("%d -> ", ptr->data);
    inorderTraversal(ptr->right);
 }

void postorderTraversal(struct Node* ptr) 
 {
    if (ptr == NULL)
        return;

    postorderTraversal(ptr->left);
    postorderTraversal(ptr->right);
    printf("%d -> ", ptr->data);
 }

struct Node* deletion(struct Node* root, int data)
 {
    if (root == NULL) 
        return root;
    

    if (data < root->data) 
        root->left = deletion(root->left, data);
    
    else if (data > root->data) 
        root->right = deletion(root->right, data);
    
    else 
     {
        if (root->left == NULL) 
         {
            struct Node* temp = root->right;
            free(root);
            return temp;
         }
        else if (root->right == NULL) 
         {
            struct Node* temp = root->left;
            free(root);
            return temp;
         }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
     }

    return root;
}

struct Node* minValueNode(struct Node* node)
 {
    struct Node* current = node;

    while (current && current->left != NULL) 
        current = current->left;
    
    return current;
 }

int searchElement(struct Node* ptr, int data)
 {
    if (ptr == NULL)
        return 0;  

    if (data == ptr->data)
        return 1; 

    if (data < ptr->data)
        return searchElement(ptr->left, data);  

    return searchElement(ptr->right, data);  
 }



