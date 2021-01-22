#include<stdio.h>
#include<stdlib.h>

int q[5] = {50,40,30,20,10};
int f=0,r=4;

int main()
{
    while(q[0]!=0)
    {
        for(int i=f;i<=r;i++)
        {
            printf("Thread given to Task %d and value before its execution: %d\n",(i+1),q[i]);
            q [i]-= 10;
            if(q[r]==0)
                r--;
            if(q[f]==0)
                f++;
            
            printf("After execution : %d\n",q[i]);
            printf("==================================================\n");
        }
    }
}
