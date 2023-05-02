#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

const int MAX_SIZE = 50;
int TOP=-1;

struct Node{
    int data;
};


struct Node stackNode[MAX_SIZE];

void printStack();
void pushStack(int value);
int popStack();
int peekStack();
int lengthOfStack();


int main()
 {
    
    int element =0;
    int choice=0;

   
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to print the stack.\n");
    printf("2. Press 2 to push onto stack.\n");
    printf("3. Press 3 to pop from stack.\n");
    printf("4. Press 4 to peek stack.\n");
    printf("5. Press 5 to find length of the stack:\n");

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
               
               printf("\nElement popped from top of stack. Value: %d", popStack);
               break;       
               
       case 4: printf("\nElement on top of stack. Value: %d", peekStack());
               break;

       case 5: printf("\nLength of the stack: %d",lengthOfStack());
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
        printf("%d->", stackNode[i].data);
     printf("%d",stackNode[i].data);     
  }

 
 void pushStack(int value)
  {
     if(TOP==MAX_SIZE-1) 
        printf("\nStack overflow. Cannot push onto stack!");
               
     else
       {
        stackNode[++TOP].data = value;
        printf("\nSuccessfullly insert onto stack!");
       }
   
  }

  int popStack()
   {
     if(TOP==-1)
      {
        printf("\nStack underflow. Cannot pop from stack");
        return -1;
      }

     else
      return stackNode[TOP--].data;
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

  int lengthOfStack() 
   {
     return TOP;
   }
   