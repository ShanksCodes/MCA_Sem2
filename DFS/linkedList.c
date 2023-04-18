#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*start=NULL;

void insertFromBeginning(int value);
void insertFromEnd(int value);
void insertAtIndex(int value,int index);
void deleteFromFront();
void deleteFromEnd();
void deleteAtIndex(int index);
void findMax();
void findElement(int value);
void reverseLinkedList();
void traverseLinkedList();


int main()
 {
    
    printf("\n----------------------------------------------------------\n\n");

    int choice=0;

    printf("1. Press 1 to traverse the linked list.\n");
    printf("2. Press 2 to insert a new node at the beginning.\n");
    printf("3. Press 3 to insert a new node at the end.\n");
    printf("4. Press 4 to insert node at a specific index.\n");
    printf("5. Press 5 to delete a node from the front.\n");
    printf("6. Press 6 to delete a node from the end.\n");
    printf("7. Press 7 to delete a node at a specific index.\n");
    printf("8. Press 8 to find maximum element in linked list.\n");
    printf("9. Press 9 to find an element in linked list.\n");
    printf("10. Press 10 to reverse the linked list.\n");
    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

   

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
    
     struct Node*newNode=malloc(sizeof(struct Node));
     newNode->data=value;
     newNode->next=start;
     start=newNode;
  }

  void insertFromEnd(int value)
   {
    
     struct Node*newNode=malloc(sizeof(struct Node));
     struct Node*temp=NULL;
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
   }