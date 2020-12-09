#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if(x == NULL)
    {
        printf("Memory full!");
        exit(0);
    }
    return x;
}
void freenode(NODE x)
{
    free(x);
}
NODE insert_front(int item,NODE head)
{
    NODE temp,prev;
    temp = getnode();
    temp->info = item;
    prev = head->llink;
    temp->llink = prev;
    temp->rlink = head;
    head->llink = temp;
    head = temp;
    return head;
}
NODE insert_rear(int item,NODE head)
{
    NODE temp,last;
    last = head->llink;
    temp = getnode();
    temp->info = item;
   temp->llink = last;
   temp->rlink = head;
   head->llink = temp;
    return head;
}
NODE delete_front(NODE head)
{
    NODE cur,next;
    if(head->rlink == NULL)
    {
        printf("--------DLL EMPTY---------\n");
        return head;
    }
    cur = head->rlink;
    next = cur->rlink;
    head->rlink = next;
    next->llink = head;
    printf("THE NODE DELETED IS %d\n",cur->info);
    freenode(cur);
    return head;
}
NODE delete_rear(NODE head)
{
    NODE cur,prev;
    if(head->rlink == NULL)
    {
        printf("-----DLL EMPTY--------\n");
        return head;
    }
    cur = head->llink;
    prev = cur->llink;
    head->llink = prev;
    prev->rlink = head;
    printf("========THE NODE DELETED IS %d = = =====\n",cur->info);
    freenode(cur);
    return head;
}
void display(NODE head)
{
    NODE temp;
    if(head->rlink == NULL)
    {
        printf("==========DLL EMPTY=========\n");
        return;
    }
    printf("==========CONTENTS OF DLL==========\n");
    temp = head->rlink;
    while(temp!=head)
    {
        printf("%d\n",temp->info);
        temp = temp->rlink;
    }
    printf("=====================\n");
    return;
}
NODE insert_leftpos(int item,NODE head)
{
    NODE temp,cur,prev;
    if(head->rlink == NULL)
    {
        printf("===========LIST EMPTY===========\n");
        return head;
    }
    cur = head->rlink;
    while(cur!=head)
    {
        if(item == cur->info)
            break;
        cur = cur->rlink;
    }
    if(cur == head)
    {
        printf("=============KEY NOT FOUND==============\n");
        return head;
    }
    prev = cur->llink;
    printf("ENTER TOWARDS LEFT OF %d=\n",item);
    temp = getnode();
    scanf("%d",&temp->info);
    prev->rlink = temp;
    temp->llink = prev;
    cur->llink = temp;
    temp->rlink = cur;
    return head;
}
NODE delete_all_key(int item,NODE head)
{
    NODE prev,cur,next;
    int count=0;
    if(head->rlink == NULL)
    {
        printf("===============LIST EMPTY==============\n");
        return head;
    }
    cur = head->rlink;
    while(cur!=head)
    {
        if(item!=cur->info)
            cur = cur->rlink;
        else
        {
            count++;
            prev = cur->llink;
            next = cur->rlink;
            prev->rlink = next;
            next->llink = prev;
            freenode(cur);
            cur = next;
        }
    }
    if(count == 0)
        printf("========KEY NOT FOUND========\n");
    else
        printf("====KEY FOUND AT %d POSITIONS AND ARE DELETED========\n",count);
    return head;
}
NODE search_key(int item,NODE head)
{
    NODE prev,cur,next;
    int count=0;
    if(head->rlink == NULL)
    {
        printf("===============LIST EMPTY==============\n");
        return head;
    }
    cur = head->rlink;
    while(cur!=head)
    {
        if(item!=cur->info)
            cur = cur->rlink;
        else
        {
            count++;
            cur = cur->rlink;
        }
    }
    if(count == 0)
        printf("========KEY NOT FOUND========\n");
    else
        printf("====KEY FOUND AT %d POSITIONS========\n",count);
    return head;
}
NODE insert_right(NODE head,int item)
{
    NODE temp,cur,next;
    if(head->rlink == NULL)
    {
        printf("=======LIST EMPTY======\n");
        return head;
    }
    cur = head->rlink;
    while(cur!=head)
    {
        if(item == cur->info)
            break;
        cur = cur->rlink;
    }
    if(cur == head)
    {
        printf("========KEY NOT FOUND========\n");
        return head;
    }
    next = cur->rlink;
    printf("===ENTER TOWARDS RIGHT OF %d = = \n",item);
    temp = getnode();
    scanf("%d",&temp->info);
    cur->rlink = temp;
    temp->llink = cur;
    temp->rlink = next;
    next->llink = temp;
    return head;
}
int main(void)
{
    NODE head;
    int choice,item;
    head = getnode();
    head->rlink = NULL;
    head->llink = NULL;
    for(;;)
    {
        printf("==========================================\n");
        printf("1. INSERT FRONT\n2. INSERT REAR\n3.DELETE FRONT\n4.DELETE REAR\n5.INSERT LEFT\n6.INSERT RIGHT\n7.DELETE ALL INSTANCES\n8.SEARCH\n9.DISPLAY\n10.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter the item at front end\n");
			scanf("%d",&item);
			head=insert_front(item,head);
			break;
		case 2: printf("enter the item at rear end\n");
			scanf("%d",&item);
			head=insert_rear(item,head);
			break;
		case 3:head=delete_front(head);
			break;
		case 4: head=delete_rear(head);
			break;
		case 5: printf("enter the item to left element to be added\n");
			scanf("%d",&item);
			head=insert_leftpos(item,head);
			break;
		case 6:printf("enter the item to left element to be added\n");
			scanf("%d",&item);
			head=insert_right(head,item);
			break;
		case 7: printf("Enter the item to be deleted\n");
		        scanf("%d",&item);
		        head = delete_all_key(item,head);
		        break;
		case 8: printf("Enter the item to be searched\n");
		        scanf("%d",&item);
		        head = search_key(item,head);
		        break;
		case 9: display(head);
		        break;
		default:exit(0);
		}
        }
    }
