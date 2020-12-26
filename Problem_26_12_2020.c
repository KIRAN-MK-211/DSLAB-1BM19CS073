#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char USN[10];
    char name[30];
    struct node *llink,*rlink;
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

NODE insert(NODE first,char USN[10], char name[30])
{
    NODE temp;
    temp = getnode();
    strcpy(temp->USN,USN);
    strcpy(temp->name,name);
    temp->llink = NULL;
    temp->rlink = NULL;
    if(first == NULL)
    {
        return temp;
    }
    temp->rlink = first;
    temp->llink = first->llink;
    first->llink->rlink = temp;
    first->llink = temp;
    return temp;
}

NODE delete_p(NODE first, char USN[30])
{
    NODE cur,prev;
    if(first == NULL)
    {
        printf("Empty list!\n");
    }
    cur = first;
    prev = cur->llink;
    while(cur->rlink!=first)
    {
        if(strcmp(cur->USN,USN)==0)
        {
            prev->rlink = cur->rlink;
            cur->llink = prev;
            freenode(cur);
            printf("Item deletion successful!\n");
            break;
        }
        cur = cur->rlink;
        prev = prev->rlink;
    }
    if(cur == first)
        printf("Item not found!\n");
    return first;
}

void display(NODE first)
{
    if(first == NULL)
    {
        printf("List empty!\n");
        return;
    }
    NODE cur;
    cur = first;
    printf("LIST:::\n");
    while(cur->rlink!=first)
    {
        printf("==================\n");
        printf("USN: %s\n",cur->USN);
        printf("NAME: %s\n",cur->name);
        cur = cur->rlink;
    }
    
}


int main(void)
{
    NODE first;
    first->llink = first;
    first->rlink = first;
    int choice;
    char USN[10],name[30];
    printf("DLL:::::Given Question!!\n");
    for(;;)
    {
        printf(":::::::::::::::::::::::::::::::::\n");
        printf("Enter 1.Insertion\n2.Deletion\n3.Display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter name\n");
                    scanf("%s",name);
                    printf("Enter USN\n");
                    scanf("%s",USN);
                    first = insert(first,USN,name);
                    break;
        
            case 2: printf("Enter the USN to be deleted\n");
                    scanf("%s",USN);
                    first = delete_p(first,USN);
                    break;
            case 3: display(first);
                    break;
            default: exit(0);
        }
        
    }
}
