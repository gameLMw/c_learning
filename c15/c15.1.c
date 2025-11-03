#include <stdio.h>
int main()
{
	int x=2;
	int cnt=0;
	//for(x=2; x<100;x++)
	while(cnt<3)
	{
		int i,b=1;
		for(i=2;i<x;i++)
		{
			if(x%i==0)
			{
				b=0;
				//break;//跳出循环。continue;（跳过循环）。 
			}
		}
		if(b==1)
		{
			printf("%d\n",x);
			cnt++;
		} 
		x++;
    }
	return 0;
}
