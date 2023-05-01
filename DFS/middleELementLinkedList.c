#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*start=NULL;

void traverseLinkedList();
void insertFromBeginning(int value);
void insertFromEnd(int value);
void insertAtPosition(int value,int position);
int middleElement(); 

int main()
 {
    
    int choice=0;
    int val=0;
    int element=0;
    int position=-1;
 
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to traverse the linked list.\n");
    printf("2. Press 2 to insert a new node at the beginning.\n");
    printf("3. Press 3 to insert a new node at the end.\n");
    printf("4. Press 4 to insert node at a specific position.\n");
    printf("5. Press 5 to find the middle element in the linked list\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nTraversing linked list from the front...\n");
               traverseLinkedList();
               break;

       case 2: printf("\nInsertion from front:\nEnter element to insert at front: ");
               scanf("%d", &element);
               insertFromBeginning(element);
               break;

       case 3: printf("\nInsertion from end\nEnter element to insert at the end: ");
               scanf("%d", &element);
               insertFromEnd(element);
               break;

       case 4: printf("\nInsertion at specific position\nEnter element and position where new node must be added respectively: ");
               scanf("%d%d", &element,&position);
               insertAtPosition(element,position); 
               break;

       case 5: val = middleElement();
               if(val==-1)
                printf("\nLinked list is empty.");
                
               else 
                printf("\nMiddle element is %d",val); 
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

 void traverseLinkedList()
  {
     struct Node*temp=start;

     if(start==NULL)
       {
         printf("\nLinked list is empty.\n");
         return;
       }

     while(temp->next!=NULL) //usually it is temp->NULL as per standards, but change is to print -> effectively
      {
          printf("%d --> ",temp->data);
          temp=temp->next;
      }

     printf("%d",temp->data);
     temp=temp->next;
  }

 void insertFromBeginning(int value)
  {
  
      struct Node*newNode = NULL; 

        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=value;
        newNode->next=start;
        start=newNode;

        printf("\nNew node successfully inserted!");
      
  }

  void insertFromEnd(int value)
   {
    
     struct Node*newNode=NULL;
     struct Node*temp=NULL;

        temp=start;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data=value;
   
        if(start==NULL)
         {
           start=newNode;
           newNode->next=NULL;
           printf("New node successfully inserted!");
           return;
         }
   
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=NULL;
    
        printf("New node successfully inserted!");  
   }


  void insertAtPosition(int value,int position)
   {
     struct Node*newNode = NULL;
     struct Node*temp=NULL;
     struct Node*temp2=NULL;
     int i=0;
     temp=start;
     newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data=value;
     if(start==NULL)
      {
        start=newNode;
        newNode->next=NULL;
        printf("New node successfully inserted!");
        return;
      }
     
     while(i<position-1)
      {
        temp=temp->next;
        i++;
      }
     temp2=temp->next;
     temp->next=newNode;
     newNode->next=temp2;
     printf("New node successfully inserted!");
   }

  int middleElement()
   {
      struct Node*fast=start;
      struct Node*slow=start;

      while(fast!=NULL && fast->next!=NULL)
       {
         fast=fast->next->next;
         slow=slow->next;
       }

       return slow->data;
   }