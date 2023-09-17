#include <stdio.h>
 
int N,M;
int a[1000];
int b[1000];
 
void f(int c)
{
    int i;
    
    if(c==M)
    {
        for(i=0;i<M;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    else
    {
        for(i=1 ; i<=N ; i++)
        {
            if(b[i]==0)
            {
                a[c] = i;
                b[i]=1;
                f(c+1);
                b[i]=0;
            }
        }
    }
}    
    
 
int main(void) {
    scanf("%d %d",&N,&M);
    f(0);
} 