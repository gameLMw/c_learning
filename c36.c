#include <stdio.h>
#include <string.h>
void stsrt(char *ar,int n);
int main(void)
{
    int n;
    scanf("%d",&n);
    char ar[n+1];
    for (int i=0;i<n;i++)
    {
        scanf(" %c",&ar[i]);
    }
    ar[n]='\0';
    stsrt(ar,n);
    printf("%s\n",ar);
    return 0;
}
void stsrt(char *ar,int n)
{
     char temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ar[i]>ar[j])
            {
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
}