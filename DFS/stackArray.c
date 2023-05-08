#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_SIZE 50

int TOP=-1;

struct Node{
    int data;
};


struct Node stackNode[MAX_SIZE];

void printStack();
void pushStack(int value);
int popStack();
int peekStack();
int searchElement(int);
int lengthOfStack();


int main()
 {
    
    int element =0;
    int choice=0;
    int pos=-1;

   
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to print the stack.\n");
    printf("2. Press 2 to push onto stack.\n");
    printf("3. Press 3 to pop from stack.\n");
    printf("4. Press 4 to peek stack.\n");
    printf("5. Press 5 to search an element in stack\n");
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
               printf("\nElement found at array index(0 based) %d ", searchElement(element));
               break;

       case 6: printf("\nLength of the stack: %d",lengthOfStack());
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

 void printStack()
  {
     int i=TOP;

     while(i>=1)
       {
        printf("%d->", stackNode[i].data);
        --i;
       }
     printf("%d",stackNode[i].data);     
  }

 
 void pushStack(int value)
  {
     if(TOP==MAX_SIZE-1) 
        printf("\nStack overflow. Cannot push onto stack!");
               
     else
       {
        stackNode[++TOP].data = value;
        printf("\nSuccessfullly inserted onto stack!");
       }
   
  }

  int popStack()
   {
     int val=-1;
     if(TOP==-1)
      {
        printf("\nStack is empty");
        return -1;
      }

     else
      val= stackNode[TOP--].data;
     return val;
   }

 int peekStack()
  {
    if(TOP==-1)
      {
        printf("\nStack underflow. Cannot pop from stack");
        return -1;
      }

     else
      return stackNode[TOP].data;
  }

 int searchElement(int value)
  {
    int i=TOP;
    while(i-->=0)
     {
       if(stackNode[i].data==value)
        return i;       
     }

     return -1;
  } 

  int lengthOfStack() 
   {
     return TOP+1;
   }
   

