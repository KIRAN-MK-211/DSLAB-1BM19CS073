#include<stdio.h>
#include<stdlib.h>
#define N 3
int queue[3][N];
int front[3]={0,0,0};
int rear[3]={-1,-1,-1};
int item,pr;
void main()
{
int ch;
while(true)
{
printf("\n=================enter 1:insert\n2.delete\n3:display\n4:Exit\n");
scanf("%d",&ch);
switch(ch)
{
 case 1:printf("enter the priority number\n");
		scanf("%d",&pr);
		if(pr>0 && pr<4)
		pqinsert(pr-1);
		else
		printf("only 3 priority exists 1 2 3\n");
		break;
case 2:pqdelete();
	   break;
case 3:display();
	   break;
case 4:exit(0);
}
}
}
pqinsert(int pr)
{
 if(rear[pr]==N-1)
 printf("\n Queue overflow\n");
 else
 {
 printf("\nenter the item\n");
 scanf("%d",&item);
 rear[pr]++;
 queue[pr][rear[pr]]=item;
 }
 return;
}
pqdelete()
{
int i;
for(i=0;i<3;i++)
{
  if(rear[i]==front[i]-1)
  printf("\queue empty\n");
  else
  {
  printf("deleted item is %d of queue %d\n",queue[i][front[i]],i+1);
  front[i]++;
  return;
  }
 }
}
display()
{
int i,j;
for(i=0;i<3;i++)
{
if(rear[i]==front[i]-1)
  printf("\queue empty %d\n",i+1);
else
  {
  printf("\nQUEUE %d:",i+1);
  for(j=front[i];j<=rear[i];j++)
    printf("%d\t",queue[i][j]);
  }
}
  return;
}
