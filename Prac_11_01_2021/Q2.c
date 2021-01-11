/*
An Application is to be developed to manage the records of the candidates who register for
the NPTEL online course. The NPTEL has planned to conduct the course for 250 candidates
on First Come First Serve course registration basis. Once all the 250 candidates are registered
the message should be displayed as “Registration Closed” and no student is allowed to leave
the course until the completion. Identify the suitable data structureand develop an
application(C Program) for the above scenario.
*/
#include<stdio.h>
#include<string.h>
#define SIZE 5

int f=0,r=-1;

struct student
{
    char name[30];
    int id;
}s[SIZE];

void reg(char *name)
{
    int def_id = 1000;
    if(r==SIZE-1)
    {
        printf("======Registrations Are Closed. !!===========\n");
        return;
    }
    r++;
    strcpy(s[r].name,name);
    s[r].id = def_id + r;
    printf("Registered Successfully! Your ID: %d\n",s[r].id);
    
}

void del()
{
    if(f>r)
    {
        printf("No registered participants.\n");
        f=0;
	  r=-1;
	  return;
    }
        
    printf("Congratulations %s for completing your course. Your ID: %d. We shall mail your certificate to your registered mail ID. Thanks for learning on NPTEL.\n",s[f].name,s[f].id);
    f++;
    
    
}
void display()
{
   if(f>r)
   {
       printf("No participants registered for course!\n");
       return;
   }
   printf("=======REGISTERED PARTICIPANTS==========\n");
   for(int i=f;i<=r;i++)
   {
       printf("Name : %s.   ID: %d\n",s[i].name,s[i].id);
   }
}
int main(void)
{
    int choice,item;
    char name_item[30];
    for(;;)
    {
        printf("============================\n");
        printf("Enter 1.New Registration\n2.Completion of Certificate course\n3.Display  details of enrolled participants\n4.Exit from the portal\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the name of student:");
                    scanf("%s",name_item);
                    printf("\n");
                    reg(name_item);
                    break;
            case 2: del();
                    break;
            case 3: display();
                    break;
            default: exit(0);
        }
    }
}   
