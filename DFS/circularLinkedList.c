#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*tail=NULL;

void traverseCircularList();
void insertFromBeginning(int value);
void insertFromEnd(int value);
void insertAtPosition(int value,int position);
void deleteFromFront();
void deleteFromEnd();
void deleteAtPosition(int position);
int lengthOfCircularList();


int main()
 {
    
    int element =0;
    int position = -1;
    int choice=0;
   
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to traverse the circular linked list.\n");
    printf("2. Press 2 to insert a new node at the beginning.\n");
    printf("3. Press 3 to insert a new node at the end.\n");
    printf("4. Press 4 to insert node at a specific position.\n");
    printf("5. Press 5 to delete a node from the front.\n");
    printf("6. Press 6 to delete a node from the end.\n");
    printf("7. Press 7 to delete a node at a specific index.\n");
    printf("8. Press 11 to find length of the linked list:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nTraversing the circular linked list...\n");
               traverseCircularList();
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

       case 8: printf("\nLength of the linked list: %d\n",lengthOfCircularList());
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

 void traverseCircularList()
  {
     struct Node*temp=tail->next;
     struct Node*firstNode = tail->next;

     if(tail==NULL)
       {
         printf("\nLinked list is empty.\n");
         return;
       }

     while(temp->next!=firstNode) //usually it is temp->NULL as per standards, but change is to print -> effectively
      {
          printf("%d --> ",temp->data);
          temp=temp->next;
      }

     printf("%d",temp->data);
     
  }

 void insertFromBeginning(int value)
  {
  
    struct Node*newNode = NULL;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;

    if(tail==NULL)
      {
          newNode->next = newNode;
          tail= newNode;
          printf("\nNew node successfully inserted!");
          return;
      }


      newNode->next=tail->next;
      tail->next=newNode;
   
             
  }

  void insertFromEnd(int value)
   {
    
      struct Node*newNode = NULL; 

      newNode=(struct Node*)malloc(sizeof(struct Node));
      newNode->data=value;
   
      if(tail==NULL)
        {
          newNode->next = newNode;
          tail= newNode;
          printf("\nNew node successfully inserted!");
          return;
        }
    
      newNode->next=tail->next;
      tail->next=newNode;
      tail=newNode;
   }


  void insertAtPosition(int value,int position)
   {
     struct Node*newNode = NULL;
     struct Node*temp=NULL;
     struct Node*temp2=NULL;
     int i=0;
     temp=tail->next;
     newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data=value;
     if(tail==NULL)
      {
        tail=newNode;
        newNode->next=newNode;
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
      
      if(tail==NULL)
       {
         printf("\nLinked list is empty.\n");
         return;
       }

      struct Node*temp=NULL;
      temp=tail->next;
      tail->next = temp->next;
      free(temp);
      printf("Node deleted from end successfully.");

    }

  
  void deleteFromEnd()
    {
      
     if(tail==NULL)
       {
          printf("\nLinked list is empty.\n");
          return;
       }

      struct Node*temp=NULL;
      struct Node*temp2=NULL;
      temp=tail->next;
      while(temp->next!=tail)
       {
         temp=temp->next;
       }

      temp2 = temp->next;
      temp->next=tail->next;
      tail=temp;

      free(temp2);
      printf("Node deleted from end successfully.");
    }


  void deleteAtPosition(int position)
   {
     
    if(tail==NULL)
       {
         printf("\nLinked list is empty.\n");     
         return;
       }

    if (position == 0)
      {
        struct Node* temp = tail->next;
        if(temp->next!=tail)
          start = start->next;
          
        free(temp);
        printf("Node at position %d deleted successfully.", position);
        return;
      }  

     struct Node*temp=tail->next;
     int i=0;
    
     while(i<position-1)
      {
        temp=temp->next;
        i++;
      }

      temp->next=temp->next->next;
      temp=temp->next;
      free(temp);

     printf("Node deleted from end successfully.");
   }
  
int lengthOfCircularList()
 {
   
   if(tail==NULL)
    return 0;
   
    struct Node*temp=tail->next;
    struct Node*firstNode=tail->next;

    int i=0;
    do
     {
        i++;
        temp=temp->next;
     }while(temp!=firstNode);

    return i;
 }
