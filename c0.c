#include <stdio.h>
int main()
{
//	printf("sizeof(char)=%ld\n",sizeof(char));
//	printf("sizeof(shrot)=%ld\n",sizeof(short));
//	printf("sizeof(int)=%ld\n",sizeof(int));
//    printf("sizeof(long)=%ld\n",sizeof(long));//在32位中long只有4字节
	int x=0,y=0,z=0,n=0,m=0;
	x=1;
	y=x++;
	printf("y=%d x=%d z=%d n=%d\n",y,x,z,x++);
//	printf("sizeof(long long)=%ld\n",sizeof(long long));
	return 0;
}
