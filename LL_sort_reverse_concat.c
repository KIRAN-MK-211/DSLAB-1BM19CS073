//This code requires minor changes
#include<stdio.h>
#include<stdlib.h>
int total = 0;


struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
void swap(NODE,NODE);
void display();
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if(x == NULL)
    {
        printf("Memory full!\n");
        exit(0);
    }
    return x;
}
void freenode(NODE x)
{
    free(x);
}
NODE delete_pos(int pos,NODE first)
{
    NODE cur,prev;
    int count;
    if(first == NULL)
    {
        printf("==============LIST EMPTY!Cannot delete=========\n");
        return NULL;
    }
    if(pos<0)
    {
        printf("===============Invalid position============\n");
        return NULL;
    }
    if(pos==1)
    {
        cur = first;
        first = first->link;
        freenode(first);
        total--;
        printf("=============Deletion successfull===========\n");
        return first;
    }
    prev = first;
    cur=prev->link;
    count = 1;
    while(cur!=NULL && count != pos - 1 )
    {
        prev = cur;
        cur = cur->link;
        count++;
    }
    if(count!=pos-1)
    {
        printf("==========Invalid position==========\n ");
        return first;
    }
    printf("=============Deletion successfull===========\n");
    prev->link = cur->link;
    total--;
    freenode(cur);
    return first;
}

void display(NODE first,NODE second)
{
    NODE temp;
    if(first == NULL)
    {
        printf("============LIST 1 EMPTY===============\n");
        
    }
    if(second == NULL)
    {
        printf("============LIST 2 EMPTY===============\n");
        
    }
    if(second == NULL && first == NULL)
    {
        printf("============LIST 1 and 2 EMPTY===============\n");
        return;
    }
    printf("===============DETAILS OF THE LIST1============\n");
    
    for(temp = first;temp!=NULL;temp=temp->link)
    {
        printf("%d\n",temp->info);
    }
    printf("===============DETAILS OF THE LIST2============\n");
    
    for(temp = second;temp!=NULL;temp=temp->link)
    {
        printf("%d\n",temp->info);
    }
    return;
}
NODE sort_and_insert(NODE first,int item) 
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
NODE reverse(NODE first)
{
    NODE cur,temp;
    cur = NULL;
    while(first!=NULL)
    {
        temp = first;
        first = first->link;
        temp->link = cur;
        cur = temp;
    }
    return cur;
}
NODE concat(NODE first,NODE second)
{
    NODE cur;
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    cur = first;
    while(cur->link!=NULL)
        cur = cur->link;
    cur->link = second;
    return first;
}
int main(void)
{
    NODE first=NULL,second = NULL;
    int item,pos,choice;
    for(;;)
    {
        printf("======================================\n");
        printf("Enter 1.Insert in LL1\n2. Insert in LL2\n3. Delete from position from LL1\n4.Delete from position from LL2\n5.Display the Lists\n6.Reverse LL1\n7.Reverse LL2\n8.Concat both the lists\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the item to inserted\n");
                    scanf("%d",&item);
                    first = sort_and_insert(first,item);
                    break;
            case 2: printf("Enter the item to inserted\n");
                    scanf("%d",&item);
                    second = sort_and_insert(second, item);
                    break;
            case 3: printf("Enter the position to be deleted\n");
                    scanf("%d",&pos);
                    first = delete_pos(pos,first);
                    break;
            case 4: printf("Enter the position to be deleted\n");
                    scanf("%d",&pos);
                    second = delete_pos(pos,second);
                    break;
            case 5: display(first,second);
                    break;
            case 6:reverse(first);
                    break;
            case 7: reverse(second);
                    break;
            case 8: concat(first,second);
                    break;
            default: exit(0);
        }
    }
    
}
