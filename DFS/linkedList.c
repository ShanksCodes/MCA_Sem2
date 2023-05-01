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
int lengthOfLinkedList();
int searchLinkedList(int value);
void createLoop();
struct Node* detectCycle();
void removeCycle();


int main()
 {
    
    int element =0;
    int position = -1;
    int pos=-1;
    int choice=0;
    int val=0;
    struct Node*temp=NULL;
    struct Node*temp2=NULL;
   
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
    printf("11. Press 11 to find length of the linked list:\n");
    printf("12. Press 12 to search the linked list:\n");
    printf("13. Press 13 to detect cycle:\n");
    printf("14. Press 14 to remove cycle:\n");
    

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

       case 11: printf("\nLength of the linked list: %d\n",lengthOfLinkedList());
               break;

       case 12: printf("\nEnter element to search in the linked list: ");
               scanf("%d", &val);
               pos= searchLinkedList(val);
               if(pos==-1)
                printf("\nElement not found!");
               else
                printf("\nElement found at position %d (0 index based)",pos);
               break;

       case 13: printf("\nDetect cycle in the linked list:\n");
               createLoop();
               temp = detectCycle();
               if(temp==NULL)
                {
                   printf("\nNo cycle detected!");
                   break;
                }
               temp2=start;
               pos=0;
               while(temp2!=temp)
                {
                   ++pos;
                   temp2=temp2->next;
                }
               printf("\nCycle detected at position: %d (0 index based) with value: %d\n",pos,temp->data);
               break;

       case 14: printf("\nRemove cycle in the linked list:\n");
               removeCycle();
               printf("\nCycle removed successfully!");
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
      
      if(start==NULL)
       {
         printf("\nLinked list is empty.\n");
         return;
       }

      struct Node*temp=NULL;
      temp=start;
      start=start->next;
      free(temp);
      printf("Node deleted from end successfully.");
    }

  void deleteFromEnd()
    {
      
     if(start==NULL)
       {
          printf("\nLinked list is empty.\n");
          return;
       }

     else if (start->next == NULL)
       {
         free(start);
         start = NULL;
         printf("Node deleted from end successfully.");
         return;
       }
    

      struct Node*temp=NULL;
      struct Node*temp2=NULL;
      temp=start;
      while(temp->next->next!=NULL)   
        temp=temp->next;
      
      temp2=temp->next;
      temp->next=NULL;
      free(temp2);
      printf("Node deleted from end successfully.");
    }


  void deleteAtPosition(int position)
   {
     
    if(start==NULL)
       {
         printf("\nLinked list is empty.\n");
         return;
       }

    if (position == 0)
      {
        struct Node* temp = start;
        start = start->next;
        free(temp);
        printf("Node at position %d deleted successfully.", position);
        return;
      }  

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
     printf("Node deleted from end successfully.");
   }
  
  
void sortLinkedList()
 {
   struct Node* temp = start;
   struct Node* temp2 = NULL;
   int tempData=0;
   
   while(temp != NULL)
   {
      temp2 = temp->next;
      
      while(temp2 != NULL)
      {
         if(temp->data > temp2->data)
         {
            
             tempData = temp->data;
            temp->data = temp2->data;
            temp2->data = tempData;
         }
         
         temp2 = temp2->next;
      }
      
      temp = temp->next;
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


void insertInSortedLinkedList(int value)
{
    struct Node*temp = start;
    struct Node*prev = NULL;
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (temp == NULL)
     {
         start = newNode;
         return;
     }
 
    if (temp->data > value)
     {
         newNode->next = temp;
         start = newNode;
         return;
     }
 
    while (temp != NULL && temp->data < value)
     {
         prev = temp;
         temp = temp->next;
     }

    if (temp == NULL)
     {
         prev->next = newNode;
         return;
     }

    newNode->next = temp;
    prev->next = newNode;
}


int lengthOfLinkedList()
 {
    struct Node*temp=start;
    int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    return i;
 }

 int searchLinkedList(int value)
 {
    struct Node*temp=start;
    int pos=0;
    while(temp!=NULL)
     {
        if(temp->data==value)
            return pos;
         
        temp=temp->next;
        pos++;
     }
    return -1;
 }


void createLoop()
 {
   if((rand()%5+1)<5)  //manually creating 80% chance of cycle
    {
      struct Node*temp=start;
      while(temp->next!=NULL)      
        temp=temp->next;
      
      temp->next= start->next;
       
    }
                
 }

struct Node* detectCycle()
 {
   
    struct Node*slow= start;;
    struct Node*fast= start;;
    struct Node*loopNode=start;

    while(fast!=NULL && fast->next!=NULL)
     {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
         {
           while(loopNode!=slow)
            {
              loopNode=loopNode->next;
              slow=slow->next;
            }

            return loopNode;
         }
     }

     return NULL;   
 }


void removeCycle()
 {
    struct Node*temp= detectCycle();
    struct Node*temp2=temp;
    if(temp==NULL)
     {
       printf("\nNo cycle detected in the linked list!");
       return;
     }

    if(start==NULL) 
     {
       printf("\nLinked list is empty!");
       return;
     }

    while(temp2->next!=temp)
      temp2=temp2->next;
    
    temp2->next=NULL;
     
 }
