
#include <stdio.h>

int main()
{
    struct student
    {
        int st_id,age;
        float marks;
    };
    struct student details;
    printf("Hello! Enter your details and check whether you have qualified the entrance exam\n");
    printf("Enter\n");
    printf("Student ID:");
    scanf("%d",&details.st_id);
    printf("\nAge:");
    scanf("%d",&details.age);
    printf("\nMarks:");
    scanf("%f",&details.marks);
    
    if(details.age>20)
    {
        float marks1 = details.marks;
        if(marks1>=0 && marks1<=100)
        {
            if(marks1>=65)
                printf("Congratulations! You have qualified the exam. You can seek admission in our university!");
            else
                printf("Sorry! You have not qualified the exam. Better Luck next time!");
                
        }
        else
            printf("Invalid Marks! Please enter proper marks");
            
    }
    else 
    {
        if(details.marks>=0 && details.marks<=100)
            printf("Invalid Age!");
        else
            printf("Invalid Credentials! Please try again");
            
        
    }
}
