#include <stdio.h>
int main()
{
	int x;
	int one, two, five;
	for (x = 1; x <= 50; x++)
	{
		for (one = 0; one <= x * 10; one++)
		{

			for (two = 0; two <= x * 10 / 2; two++)
			{

				for (five = 0; five <= x * 10 / 5; five++)
				{
					if (one + two * 2 + five * 5 == x * 10)
					{
						printf("可以用%d个一角%d个两角%d个五角得到%d元\n", one, two, five, x);
					}
				}
			}
		}
	}
	return 0;
}
