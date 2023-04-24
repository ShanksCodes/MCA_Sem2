#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};

struct Node*start=NULL;
struct Node*end=NULL;

void traverseLinkedListFromFront();
void traverseLinkedListFromEnd();
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
    printf("1. Press 1 to traverse the linked list from the front.\n");
    printf("2. Press 2 to traverse the linked list from the end.\n");
    printf("3. Press 3 to insert a new node at the beginning.\n");
    printf("4. Press 4 to insert a new node at the end.\n");
    printf("5. Press 5 to insert node at a specific position.\n");
    printf("6. Press 6 to delete a node from the front.\n");
    printf("7. Press 7 to delete a node from the end.\n");
    printf("8. Press 8 to delete a node at a specific index.\n");
    printf("9. Press 9 to reverse the linked list\n");
    printf("10. Press 10 to sort the linked list\n");
    printf("11. Press 11 to insert into a sorted linked list:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nTraversing linked list from the front...\n");
               traverseLinkedListFromFront();
               break;

       case 2: printf("\nTraversing linked list from the end...\n");
               traverseLinkedListFromFront();
               break;         

       case 3: printf("\nInsertion from front:\nEnter element to insert at front: ");
               scanf("%d", &element);
               insertFromBeginning(element);
               break;

       case 4: printf("\nInsertion from end\nEnter element to insert at the end: ");
               scanf("%d", &element);
               insertFromEnd(element);
               break;

       case 5: printf("\nInsertion at specific position\nEnter element and position where new node must be added respectively: ");
               scanf("%d%d", &element,&position);
               insertAtPosition(element,position); 
               break;

       case 6: printf("\nDeletion from front\n");
               deleteFromFront();
               break;
              
       case 7: printf("\nDeletion from end\n");
               deleteFromEnd();
               break;

       case 8: printf("\nDeletion at specific index\nEnter the position from where the node must be deleted: ");
               scanf("%d", &position);
               deleteAtPosition(position);
               break; 
        
       case 9: printf("\nReverse the linked list\n");
               reverseLinkedList();
               break;

       case 10: printf("\nSort the linked list\n");
               sortLinkedList();
               break;
            
       case 11: printf("\nInsertion into a sorted linked list:\nEnter element to insert: ");
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

 void traverseLinkedListFromFront()
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

 void traverseLinkedListFromEnd()
   {
     struct Node*temp=end;

     if(end==NULL)
      {
        printf("\nLinked list is empty.\n");
        return;
      }

     while(temp->prev!=NULL)
      {
          printf("%d --> ",temp->data);
          temp=temp->prev;
      } 

     printf("%d",temp->data);
     temp=temp->prev;

   }
     


 void insertFromBeginning(int value)
  {
  
      struct Node*newNode = NULL; 

        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=value;

        if(start==NULL)
          {
            start=newNode;
            end=newNode;
            newNode->next=NULL;
            newNode->prev=NULL;
          }
 
        else
          {
            newNode->next=start;
            newNode->prev=NULL;
            start->prev=newNode;
            start=newNode;
          }
 

        printf("\nNew node successfully inserted!");
      
  }

  void insertFromEnd(int value)
    {
     
      struct Node*newNode= (struct Node*)malloc(sizeof(struct Node));
      newNode->data=value;
 
      if(start==NULL)
        {
          start=newNode;
          end=newNode;
          newNode->next=NULL;
          newNode->prev=NULL;
        }
 
      else
       {
         end->next=newNode;
         newNode->prev=end;
         end=newNode;
       }
 
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
        newNode->prev=NULL;
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
     newNode->prev=temp;
     newNode->next=temp2;
     temp2->prev=newNode;
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

      if(start!=NULL)     
         start->prev=NULL;
      else
         end=NULL; 

      free(temp);
    }


void deleteFromEnd() 
 {
    if (start == NULL) 
      {
        printf("List is empty. Cannot delete from end.");
        return;
      }

    struct Node* temp = end;
    end = end->prev;
   
    if (end != NULL)   
      end->next = NULL;
      
    else 
      start = NULL;

    free(temp);
    printf("Node deleted from end successfully.");
  }


  void deleteAtPosition(int position)
   {
     
     if(start==NULL)
      {
        printf("\nLinked list is empty.\n");
        return;
      }


     struct Node*temp=NULL;

     if(position == 0)
     {
       start = start->next;
       if(start != NULL)
           start->prev = NULL;
       
       free(temp);
       printf("Node deleted successfully.");
       return;
     }

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
     temp2->next->prev=temp;
     free(temp2);
     printf("Node deleted successfully.");
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


void reverseLinkedList() {
    struct Node *temp = NULL;
    struct Node *current = start;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        start = temp->prev;
    }
}


void insertInSortedLinkedList(int value)
{
    struct Node* temp = start;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (temp == NULL)
     {
        start = newNode;
        return;
     }

    if (temp->data > value)
      {
        newNode->next = temp;
        temp->prev = newNode;
        start = newNode;
        return;
      }

    while (temp != NULL && temp->data < value)
       temp = temp->next;
    

    if (temp == NULL)
     {
        newNode->prev = end;
        end->next = newNode;
        end = newNode;
        return;
     }

    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}
