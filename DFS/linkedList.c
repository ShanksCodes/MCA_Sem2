#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*start=NULL;

void traverseLinkedList();
void insertFromBeginning(int value);
void insertFromEnd(int value);
//void insertAtIndex(int value,int index);
//void deleteFromFront();
//void deleteFromEnd();
//void deleteAtIndex(int index);


int main()
 {
    

    int element =0;
    int index = -1;
    int choice=0;

   
  for(;;)
   {
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to traverse the linked list.\n");
    printf("2. Press 2 to insert a new node at the beginning.\n");
    printf("3. Press 3 to insert a new node at the end.\n");
    printf("4. Press 4 to insert node at a specific index.\n");
    printf("5. Press 5 to delete a node from the front.\n");
    printf("6. Press 6 to delete a node from the end.\n");
    printf("7. Press 7 to delete a node at a specific index.\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nTraversing linked list from the front...");
               traverseLinkedList();
               break;

       case 2: printf("\nEnter element to insert at front: ");
               scanf("%d", &element);
               insertFromBeginning(element);
               break;

       case 3: printf("\nEnter element to insert at the end: ");
               scanf("%d", &element);
               insertFromEnd(element);
               break;

       case 4: printf("\nEnter element and index where new node must be added respectively: ");
               scanf("%d%d", &element,&index);
           //    insertFromEnd(element,index); 
               break;

       case -1: break;
       default: printf("\nInvalid entry!");                                   
     }
   }

   
    printf("\n----------------------------------------------------------\n\n");
    return 0;
 }

 void traverseLinkedList()
 {
     struct Node*temp=start;
     int counter=1;

     if(start==NULL)
       {
         printf("\nLinked list is empty.\n");
         return;
       }

     while(temp!=NULL)
     {
         printf("\ndNode %d: %d",counter,temp->data);
         temp=temp->next;
     }
 }

 void insertFromBeginning(int value)
  {
  
     int funcChoice=1;
      struct Node*newNode = NULL; 
     while(funcChoice==1)
      {
        funcChoice=0;  
  
        newNode=malloc(sizeof(struct Node));
        newNode->data=value;
        newNode->next=start;
        start=newNode;

        printf("\nNew node successfully inserted!");
        printf("\nPress 1 to insert another node. Any other key to exit: ");
        scanf("%d", &funcChoice);

      }
  }

  void insertFromEnd(int value)
   {
    
     int funcChoice=1;
     struct Node*newNode=NULL;
     struct Node*temp=NULL;

     while(funcChoice==1)
      {
        funcChoice=0;
        temp=start;
        newNode = malloc(sizeof(struct Node));
        newNode->data=value;
   
        if(start==NULL)
         {
           start=newNode;
           newNode->next=NULL;
           return;
         }
   
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=NULL;
    
        printf("\nNew node successfully inserted!");
        printf("\nPress 1 to insert another node. Any other key to exit: ");
        scanf("%d", &funcChoice);
      }
   }

