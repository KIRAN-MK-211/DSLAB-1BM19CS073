#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    float co;
    float px;
    float py;
    struct node *link;
};
typedef struct node *NODE;

float evaluate(float x,float y,NODE head );
void display(NODE head);
NODE insert(float c,float px,float py,NODE head);

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory full\n");
        exit(0);
    }
    return x;
}

void freenode(NODE x)
{
    free(x);
}

int main(void)
{
    NODE head=NULL;
    int choice;
    float c,px,py;
    for(;;)
    {
        printf("Enter the coefficient of the term. To terminate enter 0\n");
        scanf("%f",&c);
        if(c==0)
            break;
        printf("Enter the power of x and y\n");
        scanf("%f%f",&px,&py);
        head = insert(c,px,py,head);
    }
    printf("Enter the values of x and y\n");
    scanf("%f%f",&px,&py);
    float res = evaluate(px,py,head);
    display(head);
    printf("Result of the expression = %f",res);
}
NODE insert(float c,float px,float py,NODE head)
{
    NODE temp;
    temp = getnode();
    temp->link = NULL;
    temp->co = c;
    temp->px = px;
    temp->py = py;
    if(head == NULL)
        return temp;
    temp->link = head;
    head = temp;
    return head;
}
float evaluate(float x,float y,NODE head)
{
    NODE cur,temp;
    float val=0;
    cur = head;
    while(cur!=NULL)
    {
        val = val + (cur->co * (pow(x,cur->px))*(pow(y,cur->py)));
        cur = cur->link;
    }
    return val;
}
void display(NODE head)
{
    NODE cur;
    cur = head;
    if(head == NULL)
        printf("Equation does not exist\n");
    printf("Equation:\n");
    while(cur!=NULL)
    {
        printf("%.2f * x^%.2f * y^%.2f + ",cur->co,cur->px,cur->py);
        cur = cur->link;
    }
    printf("\n");
}
