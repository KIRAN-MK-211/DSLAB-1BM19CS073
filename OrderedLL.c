#include<stdio.h>
#include<stdlib.h>


struct node
{
    int info;
    struct node *link;
}; typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if(x == NULL)
    {
        printf("===============Memory full!!==========\n");
        exit(0);
    }
    return x;
}

void freenode(NODE x)
{
    free(x);
}
NODE order_list(NODE first,int item)
{
    NODE temp,prev,cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if(first == NULL)
        return temp;
    if(item > first->info)//for ascending order , if(item < first->info)
    {
        temp->link = first;
        return temp;
    }
    prev = NULL;
    cur = first;
    while(cur!=NULL && item < cur->info)//for ascending order, item > cur->info
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = temp;
    temp->link = cur;
    return first;
}
NODE delete_front(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("==================LIST EMPTY!Cannot delete===========\n");
        return first;
    }
    temp = first;
    temp = temp->link;
    printf("===========Item deleted at front end is = %d============\n",first->info);
    free(first);
    return temp;
    
}
NODE delete_rear(NODE first)
{
    NODE cur,prev;
    if(first == NULL)
    {
        printf("==================LIST EMPTY!Cannot delete===========\n");
        return first;
    }
    if(first->link == NULL)
    {
        printf("==========Item deleted at rear end is = %d=======\n",first->info);
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("==========Item deleted at rear end is = %d=======\n",cur->info);
        free(cur);
        prev->link = NULL;
        return first;
}

void display(NODE first)
{
    NODE temp;
    if(first == NULL )
    {
        printf("==================LIST EMPTY!Cannot display any item===========\n");
        return;
    }
    printf("================LIST ITEMS:::=========\n");
    for(temp = first;temp!= NULL;temp = temp->link)
        printf("%d\n",temp->info);
}

int main()
{
    int item,choice,pos;
    NODE first=NULL;
    for(;;)
    {
        printf("====================================\n");
        printf("\n 1:Insertion \n 2:Delete_front\n 3:Delete_rear\n4:display_list\n5:Exit\n");
        printf("enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the item to be inserted\n");
	                scanf("%d",&item);
	            first=order_list(first,item);
	            break;
            case 2:first=delete_front(first);
	                break;
            
            case 3:first=delete_rear(first);
	                break;
            case 4:display(first);
	                break;
            default:exit(0);
	               break;
        }
    }
    return 0;
}
