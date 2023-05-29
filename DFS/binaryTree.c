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
struct Node* insertNode(struct Node*, int)
void inorderTraversal(struct Node*ptr);
void preorderTraversal(struct Node*ptr);
void postorderTraversal(struct Node*ptr);

int main()
 {
    
    int element =0;
    int choice=0;
    int size=-1;
    int pos=0;
  
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to insert into tree.\n");
    printf("2. Press 2 for inorder traversal.\n");
    printf("3. Press 3 for preoder traversal.\n");
    printf("4. Press 4 for postorder traversal.\n");
    printf("5. Press 5 to check if the tree is empty.\n");
    printf("6. Press 6 to find height of the tree:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\n Inserting elements...: ");
               scanf("%d", &element);
               root = createNode(element);
               break;

       case 2: printf("\nEnter element to push onto stack: ");
               scanf("%d", &element);
               pushStack(element);
               break;

       case 3: element = popStack();
               if(element!=-1)
                printf("\nElement popped from top of stack. Value: %d", element);
               break;       
               
       case 4: printf("\nElement on top of stack. Value: %d", peekStack());
               break;       
      
       case 5: printf("\nEnter element to search in stack: ");
               scanf("%d", &element);
               pos = searchElement(element);
               if(pos==-1)
                printf("\nElement not found in stack");
               else
                printf("\nElement found at %dth node from the top(top node is 1st node)", pos);
               break;

       case 6: size= lengthOfStack();
               if(size==-1)
                  printf("\nStack is empty!");
               else
                printf("\nLength of the stack: %d",size);
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

 void insertNode(struct Node*ptr, int value)
  {
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL; 
    if(root==NULL)
      root = newNode;   
    return newNode;
  }

 void isEmpty()
  {
    return (root==NULL);
  }

  void inorderTraversal(struct Node*ptr)
   {
     if(isEmpty())
      {
        printf("\nTree is empty!");
        return;
      }

     inorderTraversal(ptr->left);
     printf("%d->", ptr->val);
     inorderTraversal(ptr->right); 
   }

   void preorderTraversal(struct Node*ptr)
    {     
      if(isEmpty())
        {
          printf("\nTree is empty!");
          return;
        }
     
     printf("%d->", ptr->val);  
     inorderTraversal(ptr->left);
     inorderTraversal(ptr->right); 
        
    } 

   void postorderTraversal(struct Node*ptr)
    {      
      if(isEmpty())
        {
          printf("\nTree is empty!");
          return;
        }  
     inorderTraversal(ptr->left);
     inorderTraversal(ptr->right); 
     printf("%d->", ptr->val);  

    } 