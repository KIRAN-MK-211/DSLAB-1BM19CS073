#include<stdio.h>
#include<stdlib.h>
#define PQS 5
int f=0,r=-1,item,q[10];
void insert()
{
    if(r == PQS - 1)
        printf("====================================\nQueue Overflow!\n");
    q[++r] = item;
    sort();
}
void sort()
{
    int i,key,j;  
    for (i=1;i<=r;i++) 
    {  
        key = q[i];  
        j = i-1;  
        while (j >= 0 && q[j] < key) //for Ascending order:::: while(j>=0 && q[j]>key)
        {  
            q[j + 1] = q[j];  
            j = j - 1;  
        }  
        q[j + 1] = key;  
    }  
  
}
int delete()
{
    if(r == -1)
        printf("==========================\nQueue Underflow\n");
    else
        return q[f++];
      
}
void display()
{
    int i;
    if(r == -1)
        printf("===========\n QUEUE UNDERFLOW!!\n================\n");
    printf("=========================\nThe elements of the queue are:\n");
    for(i=f;i<=r;i++)
    {
        printf("%d\n",q[i]);
    }
}
void main()
{
    int ch;
    for(;;)
    {
        printf("==========================\n");
        printf("Enter \n1.for insertion \n2. deletion\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2: item = delete();
                    if(item == -1)
                        printf("==============\nQueue underflow\n========\n");
                    else
                        printf("===========\nItem popped = %d\n==============\n",item);
                    break;
            case 3: display();
                    break;
            default: exit(0);
        }
    }
}
