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
void deleteFromFront();
void deleteFromEnd();
void deleteAtPosition(int position);
void reverseLinkedList();
void sortLinkedList();
void insertInSortedLinkedList(int value);


int main()
 {
    

    int element =0;
    int position = -1;
    int choice=0;
   
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to traverse the linked list.\n");
    printf("2. Press 2 to insert a new node at the beginning.\n");
    printf("3. Press 3 to insert a new node at the end.\n");
    printf("4. Press 4 to insert node at a specific position.\n");
    printf("5. Press 5 to delete a node from the front.\n");
    printf("6. Press 6 to delete a node from the end.\n");
    printf("7. Press 7 to delete a node at a specific index.\n");
    printf("8. Press 8 to reverse the linked list\n");
    printf("9. Press 9 to sort the linked list\n");
    printf("10. Press 10 to insert into a sorted linked list:\n");

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
               insertFromEnd(element,position); 
               break;

       case 5: printf("\nDeletion from front\n");
               deleteFromFront();
               break;
              
       case 6: printf("\nDeletion from end\n");
               deleteFromEnd();
               break;

       case 7: printf("\nDeletion at specific index\nEnter the position from where the node must be deleted: ");
               scanf("%d", &position);
               deleteAtPosition(position);
               break; 
        
       case 8: printf("\nReverse the linked list\n");
               reverseLinkedList();
               break;

       case 9: printf("\nSort the linked list\n");
               sortLinkedList();
               break;
            
       case 10: printf("\nInsertion into a sorted linked list:\nEnter element to insert: ");
               scanf("%d", &element);
               insertInSortedLinkedList(element);
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

  void deleteFromFront()
    {
      struct Node*temp=NULL;
      temp=start;
      start=start->next;
      free(temp);
    }

  void deleteFromEnd()
    {
      struct Node*temp=NULL;
      struct Node*temp2=NULL;
      temp=start;
      while(temp->next->next!=NULL)   
        temp=temp->next;
      
      temp2=temp->next;
      temp->next=NULL;
      free(temp2);
    }


  void deleteFromPosition(int position)
   {
     struct Node*temp=NULL;
     struct Node*temp2=NULL;
     int i=0;
     temp=start;
     while(i<position-1)
      {
        temp=temp->next;
        i++;
      }
     temp2=temp->next;
     temp->next=temp2->next;
     free(temp2);
   }
  
  
 void sortLinkedList()
 {
   struct Node*temp=NULL;
   struct Node*temp2=NULL;
   temp=start;
   while(temp!=NULL)
   {
     temp2=temp->next;
     while(temp2!=NULL)
     {
       if(temp->data>temp2->data)
       {
         temp->data=temp2->data;
         temp2->data=temp->data;
       }
       temp2=temp2->next;
     }
     temp=temp->next;
   }
 }



 void reverseLinkedList()
 {
   struct Node*temp=NULL;
   struct Node*temp2=NULL;
   temp=start;
   start=NULL;
   while(temp!=NULL)
   {
     temp2=temp->next;
     temp->next=start;
     start=temp;
     temp=temp2;
   }
 }

 void insert