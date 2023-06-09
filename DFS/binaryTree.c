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
struct Node* makeTree();
void inorderTraversal(struct Node*ptr);
void preorderTraversal(struct Node*ptr);
void postorderTraversal(struct Node*ptr);
int numberOfNodes(struct Node*ptr);
int treeHeight(struct Node*ptr);
int searchElement(struct Node*ptr, int element);

int main()
 {
    
    int element =0;
    int choice=0;
    int size=-1;
    int pos=0;
  
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to create the tree.\n");
    printf("2. Press 2 for preorder traversal.\n");
    printf("3. Press 3 for inorder traversal.\n");
    printf("4. Press 4 for postorder traversal.\n");
    printf("5. Press 5 to check if the tree is empty.\n");
    printf("6. Press 6 to count the number of nodes:\n");
    printf("7. Press 7 to find the height of the tree:\n");
    printf("8. Press 8 to search an element in binary tree:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nCreating binary tree...\n");
               root = makeTree(element);
               break;

       case 2: printf("\nPreoder treversal of tree:\n");
               if(isEmpty())
                {
                  printf("\nTree is empty!");
                  break;
                }
               preorderTraversal(root);
               break;

       case 3: printf("\nInorder treversal of tree:\n");
               if(isEmpty())
                {
                  printf("\nTree is empty!");
                  break;
                }
               inorderTraversal(root);
               break;
       
       case 4: printf("\nPostoder treversal of tree:\n");
               if(isEmpty())
                {
                  printf("\nTree is empty!");
                  break;
                }
               postorderTraversal(root);
               break;      
      
       case 5: if(isEmpty())
                printf("\nTree is empty!");
               else
                printf("\nTree is not empty!");
               break;
                       
       case 6: if(isEmpty())
                printf("\nTree is empty!");
               else
                printf("\nNumber of nodes in the binary tree: %d",numberOfNodes(root));
               break;

       case 7: if(isEmpty())
                printf("\nTree is empty!");
               else
                printf("\nHeight of the binary tree: %d", treeHeight(root));
               break;

       case 8: if(isEmpty())
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
   
  struct Node* makeTree()
   {
     int val;
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
     printf("\nEnter data(-1 for no node): ");
     scanf("%d",&val);
     if(val==-1)
      return NULL;
  
     newNode->data = val;
  
     printf("\nEnter left child of %d: ",val);
     newNode->left = makeTree();                                
  
     printf("\nEnter right child of %d: ",val);
     newNode->right = makeTree();
     return newNode; 
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

int numberOfNodes(struct Node* ptr)
 {
    if (ptr == NULL)
      return 0;
    else
      return 1 + numberOfNodes(ptr->left) + numberOfNodes(ptr->right);
 }    


int treeHeight(struct Node* ptr) 
  {
    
    if (ptr == NULL)
      return 0;
    else 
     {
      int leftHeight = treeHeight(ptr->left);
      int rightHeight = treeHeight(ptr->right);
      return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
     }
  }

int searchElement(struct Node* ptr, int element) 
 {
    if (ptr == NULL)
        return 0;
    else if (ptr->data == element)
        return 1;
    else 
     {
        int foundLeft = searchElement(ptr->left, element);
        int foundRight = searchElement(ptr->right, element);
        return foundLeft || foundRight;
     }
} 

