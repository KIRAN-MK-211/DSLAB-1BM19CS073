/*Consider two students reading the word. The first student reads from left to right and the
second student was reads from right to left. After reading both the student spelled out the
same word. Develop an application (C Program) to simulate the above situation using suitable
data structure.*/

#include<stdio.h>
#include<string.h>

int main()
{
    char s[30],rev[30];
    int i,l=0;
    printf("Enter the string\n");
    scanf("%s",s);
    for(i=strlen(s)-1;i>=0;i--)
    {
       rev[l] = s[i];
       l++;
    }
    printf("Student 1 reads string as %s\n",s);
    printf("Student 2 reads string as %s\n",rev);
}
