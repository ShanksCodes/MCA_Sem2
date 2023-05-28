#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct Node{
    int data;
    struct Node*next;
};


struct Node*TOP1=NULL;
struct Node*TOP2=NULL;

void printStack();
void pushStack(int value, struct Node*);
int popStack();
int peekStack();
int searchElement(int);
int lengthOfStack();

int main()
 {
    
    int element =0;
    int choice=0;
    int size=-1;
    int pos=0;

   
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to print the stack.\n");
    printf("2. Press 2 to push onto stack.\n");
    printf("3. Press 3 to pop from stack.\n");
    printf("4. Press 4 to peek stack.\n");
    printf("5. Press 5 to find an element in stack.\n");
    printf("6. Press 6 to find length of the stack:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nStack is as follows from the top:\n");
               printStack();
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


void enqueue(int value)
 {
    int poppedVal = 0;
    TOP2 = NULL;
    pushStack(value, TOP1);
    while(!isEmpty())
     {
       poppedVal = popStack();
       pushStack(poppedVal, TOP2);

     }  

 }


 void printStack()
  {
     struct Node*temp=TOP;

     if(TOP==NULL)
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

 
 void pushStack(int , struct Node*)
  {
      struct Node*newNode = (struct Node*)malloc(sizeof(struct Node)); 

      newNode->data=value;
      newNode->next=TOP;
      TOP=newNode;

      printf("\nNew node successfully pushed!");              
  }

  int popStack()
   {
      
      int val=0;
      if(TOP==NULL)
       {
         printf("\nStack is empty!\n");
         return -1;
       }

      struct Node*temp=NULL;
      temp=TOP;
      val=temp->data;
      TOP=TOP->next;
      free(temp);
      return val;
   }

 int peekStack()
  {
    if(TOP==NULL)
      {
        printf("\nStack is empty");
        return -1;
      }

    return TOP->data;
  }


 int searchElement(int value)
  {
    int i=1;
    struct Node*temp=TOP;
    if(TOP==NULL)
     return -1;

    while(temp!=NULL)
     {
       if(temp->data==value)
        {
          return i;
        }
        i++;
        temp=temp->next;
     }
  }

  int lengthOfStack() 
   {
     struct Node*temp=TOP;
     int counter=0;
     if(TOP==NULL)
        return -1;

      
     while(temp!=NULL)
      {
        counter++;
        temp=temp->next;
      }

      return counter;
   }
   