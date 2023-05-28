#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_SIZE 50

int FRONT1=-1;
int REAR1=-1;
int FRONT2=-1;
int REAR2=-1;
int TOP =-1;

struct Node{
    int data;
};


struct Node queue1[MAX_SIZE];
struct Node queue2[MAX_SIZE];

void printStack();
void pushStack(int value);
int popStack();
int peekStack();
int searchElement(int);
int lengthOfStack();

void enqueue1(int value);
int dequeue1();
void enqueue2(int value);
int dequeue2();


int main()
 {
    
    int element =0;
    int choice=0;
    int pos=-1;

   
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to print the stack.\n");
    printf("2. Press 2 to push.\n");
    printf("3. Press 3 to pop.\n");
    printf("4. Press 4 to peek stack.\n");
    printf("5. Press 5 to search an element in stack\n");
    printf("6. Press 6 to find length of the stack:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nStack:\n");
               printStack();
               break;

       case 2: printf("\nEnter element to push: ");
               scanf("%d", &element);
               pushStack(element);
               break;

       case 3: element = popStack();
               if(element!=-1)
                printf("\nElement dequeue. Value: %d", element);
               break;       
               
       case 4: element = peekStack();
               if(element!=-1)
                printf("\nElement in the front of stack: %d", element);
               break;
               
       case 5: printf("\nEnter element to search in stack: ");
               scanf("%d", &element);
               pos = searchElement(element);
              
               if(pos==-1)
                printf("\nElement not found in stack");
               else  
               printf("\nElement found at array index(0 based) %d ", searchElement(element));
               break;

       case 6: printf("\nLength of stack: %d",lengthOfStack());
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
     int i=FRONT1;

     if(FRONT1==-1 || FRONT1>REAR1)
      {
        printf("\nStack is empty");
        return;
      }

     while(i<REAR1)
       {
        printf("%d->", queue1[i].data);
        ++i;
       }

     printf("%d", queue1[i].data);     
  }

 int lengthOfStack()
  {
     return (REAR1-FRONT1+1);
  } 

 int peekStack()
  {
     if(FRONT1==-1)
      {
        printf("\nStack underflow. Cannot peek!");
        return -1;
      }

     return queue1[REAR1].data; 
  } 

 int searchElement(int value)
  {
     int i=FRONT1;
     int pos=-1;

     if(FRONT1==-1 || FRONT1>REAR1)
      {
        printf("\nStack is empty");
        return -1;
      }

     for(i=FRONT1;i<=REAR1;i++) 
        if(queue1[i].data==value)
          return i;

     return -1;  
      
  }   

 void pushStack(int value)
  {
     if(TOP==MAX_SIZE-1)
      {
        printf("\nStack overflow. Cannot push!");
        return;
      }

     enqueue1(value);
     ++TOP;
  }


 int popStack()
  {
    int val=-1;
    int val2=-1;
    int i=0;
    if(FRONT1==-1)
      {
        printf("\nStack underflow. Cannot pop!");
        return -1;
      }
    
    if(FRONT1==REAR1)
      {
        val = dequeue1();
        FRONT1=-1;
        REAR1=-1;
        TOP=-1;
        return val;
      }

    for(i=FRONT1;i<REAR1;i++)
      {
        val = dequeue1();
        enqueue2(val);
      }

      val = dequeue1();
      val2 = val;
      FRONT1=-1;
      REAR1=-1;
      TOP=-1;
    
     for(i=FRONT2;i<=REAR2;i++)
      {
        val = dequeue2();
        enqueue1(val);
      }

      FRONT2=-1;
      REAR2=-1;

      return val2;
  
  }


 void enqueue1(int value)
  {
    if(FRONT1==-1)
       FRONT1++;
      
    queue1[++REAR1].data = value;
     
  }

 void enqueue2(int value)
  {
    if(FRONT2==-1)
       FRONT2++;
    
    queue2[++REAR2].data = value;
 
  }

  int dequeue1()
   {
     int val=-1;

     val = queue1[FRONT1].data;
     FRONT1++;

     return val;
   }

  int dequeue2()
   {
     int val=-1;

     val = queue2[FRONT2].data;
     FRONT2++;

     return val;
   } 

 