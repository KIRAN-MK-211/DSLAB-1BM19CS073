#include<stdio.h>
#include<stdlib.h>
void display();
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
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
    freenode(cur);
    return first;
}
NODE insert_pos(NODE first,int key,int pos)
{
    int count;
    NODE cur,temp,prev;
    temp = getnode();
    temp->info = key;
    temp->link = NULL;
    if(first == NULL && pos == 1)
    {
        return temp;
    }
    if(first == NULL)
    {
        printf("=============INVALID POSITION==========\n");
        return NULL;
    }
    if(pos == 1)
    {
        temp->link = first;
        return temp;
    }
    count = 1;
    prev = NULL;
    cur = first;
    while(cur!=NULL && count!=pos)
    {
        prev = cur;
        cur = cur->link;
        count++;
    }
    if(count == pos)
    {
        prev->link = temp;
        temp->link = cur;
        return first;
    }
    printf("================INVALID POSITION===============\n");
    return first;
}
void display(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("============LIST EMPTY===============\n");
        return;
    }
    printf("===============DETAILS OF THE LIST============\n");
    
    for(temp = first;temp!=NULL;temp=temp->link)
    {
        printf("%d\n",temp->info);
    }
    return;
}
int main(void)
{
    NODE first=NULL;
    int item,pos,choice;
    for(;;)
    {
        printf("======================================\n");
        printf("Enter 1.Insert at position\n2. Delete from position\n3.Display the List\n4.exit\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the position and item to inserted\n");
                    scanf("%d%d",&pos,&item);
                    first = insert_pos(first, item, pos);
                    break;
            case 2: printf("Enter the position to be deleted\n");
                    scanf("%d",&pos);
                    first = delete_pos(pos,first);
                    break;
            case 3: display(first);
                    break;
            default: exit(0);
        }
    }
    
}
