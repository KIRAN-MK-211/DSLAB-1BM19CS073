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
        printf("Mmeory full\n");
        exit(0);
    }
    return x;
}

void freenode(NODE x)
{
    free(x);
}

NODE insert(NODE root,int item)
{
    NODE temp,cur,prev;
    temp = getnode();
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if(root == NULL)
        return temp;
    cur = root;
    while(cur!=NULL)
    {
        prev = cur;
        cur = (item<cur->info)?cur->llink:cur->rlink;
    }
    if(item<prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}

void display(NODE root,int i)
{
    int j;
    if(root!=NULL)
    {
        display(root->rlink,i+1);
        for(j=0;j<i;j++)
	        printf("      ");
        printf("%d\n",root->info);
	    display(root->llink,i+1);
    }
}


NODE delete(NODE root,int item)
{
    NODE cur,parent,q,suc;
    if(root==NULL)
    {
        printf("================\nTREE EMPTY\n=============\n");
        return root;
    }
    parent=NULL;
    cur=root;
    while(cur!=NULL&&item!=cur->info)
    {
        parent=cur;
        cur=(item<cur->info)?cur->llink:cur->rlink;
    }
    if(cur==NULL)
    {
        printf("not found\n");
        return root;
    }
    if(cur->llink==NULL)
        q=cur->rlink;
    else if(cur->rlink==NULL)
        q=cur->llink;
    else
    {
        suc=cur->rlink;
        while(suc->llink!=NULL)
            suc=suc->llink;
        suc->llink=cur->llink;
        q=cur->rlink;
    }
    if(parent==NULL)
        return q;
    if(cur==parent->llink)
        parent->llink=q;
    else
        parent->rlink=q;
    freenode(cur);
    return root;
 }

void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->info);
        preorder(root->llink);
        preorder(root->rlink);
    }
    
 }
void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\n",root->info);
    }
 }
void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d\n",root->info);
        inorder(root->rlink);
    }
 }
 
 void findlargest(NODE root)
 {
     NODE cur;
     cur = root;
    if(root==NULL)
    {
        printf("================\nTREE EMPTY\n=============\n");
        return ;
    } 
    while(cur->rlink!=NULL)
    {
        cur = cur->rlink;
    }
    printf("=====The largest element in this BST is %d=========== ",cur->info);
 }
 void findsmallest(NODE root)
 {
     NODE cur;
     cur = root;
    if(root==NULL)
    {
        printf("================\nTREE EMPTY\n=============\n");
        return ;
    } 
    while(cur->llink!=NULL)
    {
        cur = cur->llink;
    }
    printf("=====The smallest element in this BST is %d=========== ",cur->info);
 }
int main(void)
{
    int item,choice;
    NODE root=NULL;
    printf("================\nBINARY SEARCH TREE\n==============\n");
    for(;;)
    {
        printf("===================\n");
        printf("\n1.INSERT \n2.DISPLAY TREE\n3.PREORDER\n4.POSTORDER\n5.INORDER\n6.DELETE\n7.FIND LARGEST ELEMENT\n8.FIND SMALLEST ELEMENT\n9.EXIT\n");
        printf("ENTER YOUR CHOICE\n");
        
        scanf("%d",&choice);
        printf("===================\n");
        switch(choice)
        {
            case 1:printf("enter the item\n");
		           scanf("%d",&item);
		           root=insert(root,item);
		           break;
            case 2:display(root,0);
		           break;
            case 3:preorder(root);
		           break;
            case 4:postorder(root);
		           break;
            case 5:inorder(root);
		           break;
            case 6:printf("enter the item\n");
		           scanf("%d",&item);
		           root=delete(root,item);
		           break;
		    case 7:findlargest(root);
		            break;
		    case 8:findsmallest(root);
		            break;
            default:exit(0);
		        
	    }
	}
 }
