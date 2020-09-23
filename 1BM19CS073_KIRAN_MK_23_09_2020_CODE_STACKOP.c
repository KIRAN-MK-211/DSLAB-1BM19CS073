#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

#define STACK_SIZE 5
int top=-1;
int s[5];
int item;
void push()
{
    if(top == STACK_SIZE - 1)
    {
        printf("STACK OVERFLOW, cannot push more elements into the stack\n");
        return;
    }
    else
    {
        top++;
        s[top] = item;
    }
}
int pop()
{
    if(top == -1)
    {
        printf("STACK UNDERFLOW, no elements in the stack\n");
        return 0;
    }
    else
    {
        return s[top--];
    }
}
void display()
{
    if(top == -1)
    {
        printf("STACK UNDERFLOW, no elements to display\n");
        return;
    }
    else
    {
        printf("The elements of the stack:\n");
        for(int i=0;i<=top;i++)
        printf("%d\n",s[i]);
    }
}
int main()
{
    int choice,item_deleted;
    
    for(;;)
    {
        printf("Enter\n1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element to be inserted\n ");
                   scanf("%d",&item);
                   push();
                   break;
            case 2: {
                item_deleted = pop();
                if(item_deleted!=0)
                printf("Item popped = %d\n",item_deleted);
                break;
            }
            case 3: display();
                    break;
            default: exit(0);
        }
    }
    getch();
}
