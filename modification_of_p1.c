
#include <stdio.h>
int main()
{
    struct student
    {
        int st_id,age;
        float marks;
    };
    struct student details[5];
    int q_id[5];
    int i,flag=0;
    
    printf("Hello! Enter details of 5 students and check whether they have qualified the entrance exam\n");
    for(i=0;i<5;i++)
    {
        printf("Enter the details of student %d\n",(i+1));
        printf("Student ID:");
        scanf("%d",&details[i].st_id);
        printf("\nAge:");
        scanf("%d",&details[i].age);
        printf("\nMarks:");
        scanf("%f",&details[i].marks);
    }
    for(i=0;i<5;i++)
    {
        if(details[i].age>20 && (details[i].marks >= 65 && details[i].marks <=100))
        {
            q_id[flag] = details[i].st_id;
            flag++;
        }
    }           
    printf("The IDs of the students who have qualified the exam\n");
    for(i=0;i<flag;i++)
        printf("%d\n",q_id[i]);
    printf("Congratulations!");
}
