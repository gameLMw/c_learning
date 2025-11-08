#include <stdio.h>
int main()
{
	int x, a = 0;
	int one, two, five;
	x = 2;
	for (one = 0; one <= x * 10; one++)
	{
		for (two = 0; two <= x * 10 / 2; two++)
		{
			for (five = 0; five <= x * 10 / 5; five++)
			{
				if (one + two * 2 + five * 5 == x * 10)
				{
					printf("可以用%d个1角%d个2角%d个5角得到%d元\n", one, two, five, x);
					a = 1;
					// break; //(接力break）
					goto out; //(goto)
				}
			} // if(a==1)break;
		} // if(a==1)break;
	}
out:
	return 0;
}
