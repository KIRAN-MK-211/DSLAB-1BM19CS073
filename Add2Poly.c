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
NODE merge(NODE head1,NODE head2);

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
    NODE head1=NULL;
    NODE head2=NULL;
    NODE head3=NULL;
    float c,px,py;
    printf("Enter the first polynomial\n");
    
    for(;;)
    {
        printf("Enter the coefficient of the term. To terminate enter 0\n");
        scanf("%f",&c);
        if(c==0)
            break;
        printf("Enter the power of x and y\n");
        scanf("%f%f",&px,&py);
        head1 = insert(c,px,py,head1);
        head3 = insert(c,px,py,head3);
    }
    
    printf("Enter the second polynomial\n");
    
    for(;;)
    {
        printf("Enter the coefficient of the term. To terminate enter 0\n");
        scanf("%f",&c);
        if(c==0)
            break;
        printf("Enter the power of x and y\n");
        scanf("%f%f",&px,&py);
        head2 = insert(c,px,py,head2);
    }
    
    
    printf("Enter the values of x and y\n");
    scanf("%f%f",&px,&py);
    display(head3);
    display(head2);
    head1 = merge(head1,head2);
    float res = evaluate(px,py,head1);
    display(head1);
    printf("Result of the expression = %f",res);
}
NODE merge(NODE head1,NODE head2)
{
    NODE head,cur1,cur2,cur,temp;
    cur1 = head1;
    cur2 = head2;
    head = cur1;
    while(cur1!=NULL)
    {
        while(cur2!=NULL)
        {
            if(cur1->px == cur2->px && cur1->py == cur2->py)
            {
                cur1->co = cur1->co + cur2->co;
                continue;
            }
            head1 = insert(cur2->co,cur2->px,cur2->py,head1);
            cur2 = cur2->link;
        }
        cur1 = cur1->link;
    }
    return head1;
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
